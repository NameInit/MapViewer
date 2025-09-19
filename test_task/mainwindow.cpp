#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
    , myScene(new MyScene(new QGraphicsScene(this)))
{
    ui->setupUi(this);
    connect(ui->lineEdit_lat, &QLineEdit::returnPressed, ui->lineEdit_lat, &QLineEdit::clearFocus);
    connect(ui->lineEdit_lon, &QLineEdit::returnPressed, ui->lineEdit_lon, &QLineEdit::clearFocus);
    connect(ui->lineEdit_zoom, &QLineEdit::returnPressed, ui->lineEdit_zoom, &QLineEdit::clearFocus);
    connect(ui->pushButton_show, &QPushButton::clicked, this, &MainWindow::ButtonShowMap);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::ViewShowMap);
    connect(myScene, &MyScene::mouseMoved, this, &MainWindow::ShowCoords);
    ui->graphicsView->setScene(myScene);
    ui->graphicsView->setMouseTracking(true);
    setFixedSize(size());

    ui->lineEdit_lat->setValidator(new QRegularExpressionValidator(QRegularExpression(
            "^-?(0|[1-7][0-9]|8[1-5])(\\.[0-9]{6})?$"
            ), this)
        );
    ui->lineEdit_lon->setValidator(new QRegularExpressionValidator(QRegularExpression(
           "^-?(0|[1-9][0-9]|1[0-7][0-9]|180)(\\.[0-9]{6})?$"
           ), this)
        );
    ui->lineEdit_zoom->setValidator(new QRegularExpressionValidator(QRegularExpression(
           "^[0-9]|1[0-9]|20$"
           ), this)
        );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::__WGS84toUTM(double lat, double lon, double &easting, double &northing, QString &zone)
{
    int zoneNumber = static_cast<int>((lon + 180.0) / 6.0) + 1;
    zone = QString("%1%2").arg(zoneNumber).arg(lat >= 0 ? 'N' : 'S');

    const double a = 6378137.0;
    const double e = 0.081819191;

    double latRad = lat * M_PI / 180.0;
    double lonRad = lon * M_PI / 180.0;
    double centralMeridian = ((zoneNumber - 1) * 6 - 180 + 3) * M_PI / 180.0;

    double N = a / sqrt(1 - e * e * sin(latRad) * sin(latRad));
    double T = tan(latRad) * tan(latRad);
    double C = e * e * cos(latRad) * cos(latRad) / (1 - e * e);
    double A = cos(latRad) * (lonRad - centralMeridian);

    double M = a * ((1 - e*e/4 - 3*e*e*e*e/64 - 5*e*e*e*e*e*e/256) * latRad
                    - (3*e*e/8 + 3*e*e*e*e/32 + 45*e*e*e*e*e*e/1024) * sin(2*latRad)
                    + (15*e*e*e*e/256 + 45*e*e*e*e*e*e/1024) * sin(4*latRad)
                    - (35*e*e*e*e*e*e/3072) * sin(6*latRad));

    easting = 0.9996 * N * (A + (1 - T + C) * A*A*A/6
                            + (5 - 18*T + T*T + 72*C - 58*e*e) * A*A*A*A*A/120) + 500000.0;

    northing = 0.9996 * (M + N * tan(latRad) * (A*A/2 + (5 - T + 9*C + 4*C*C) * A*A*A*A/24
                                                + (61 - 58*T + T*T + 600*C - 330*e*e) * A*A*A*A*A*A/720));

    if (lat < 0) {
        northing += 10000000.0;
    }
}

void MainWindow::__CalcWGS84(const QPointF &scenePos, double &lat, double &lon)
{
    double center_lat = ui->lineEdit_lat->text().toDouble();
    double center_lon = ui->lineEdit_lon->text().toDouble();
    int zoom = ui->lineEdit_zoom->text().toInt();
    QSizeF sceneSize = ui->graphicsView->scene()->sceneRect().size();
    QSize tileSize(256, 256);
    double pixelToLon = 360.0 / (pow(2, zoom) * tileSize.width());
    double pixelToLat = 170.1022 / (pow(2, zoom) * tileSize.height());
    double deltaX = scenePos.x() - sceneSize.width() / 2.0;
    double deltaY = scenePos.y() - sceneSize.height() / 2.0;
    lon = center_lon + deltaX * pixelToLon;
    lat = center_lat - deltaY * pixelToLat;
    lat = qBound(-85.05112878, lat, 85.05112878);
    lon = qBound(-180.0, lon, 180.0);
}

void MainWindow::__GetTiles(int &xtile, int &ytile)
{
    double lat = ui->lineEdit_lat->text().toDouble();
    double lon = ui->lineEdit_lon->text().toDouble();
    int zoom = ui->lineEdit_zoom->text().toInt();

    double lat_rad = lat * M_PI / 180.0;
    double n = pow(2.0, zoom);

    xtile = static_cast<int>((lon + 180.0) / 360.0 * n);
    ytile = static_cast<int>((1.0 - log(tan(lat_rad) + 1.0 / cos(lat_rad)) / M_PI) / 2.0 * n);
}

void MainWindow::ButtonShowMap()
{
    int xtile, ytile;
    __GetTiles(xtile, ytile);

    QString url = QString("https://tile.openstreetmap.org/%1/%2/%3.png").arg(ui->lineEdit_zoom->text().toInt()).arg(xtile).arg(ytile);
    QNetworkRequest request(url);
    request.setUrl(url);
    request.setRawHeader("User-Agent", "Mozilla/5.0 (X11; Ubuntu; Linux x86_64)");
    networkManager->get(request);
}

void MainWindow::ShowCoords(const QPointF &scenePos)
{
    if(ui->graphicsView->scene()->items().size()==0){
        return;
    }
    double lon, lat;
    __CalcWGS84(scenePos,lat,lon);
    ui->label_wgs84->setText(
        QString("WGS84: (%1;%2)")
            .arg(lat)
            .arg(lon)
        );

    QString utmZone;
    double easting, northing;
    __WGS84toUTM(lat,lon,easting,northing,utmZone);
    ui->label_utm->setText(
        QString("UTM: %1 (%2;%3)")
            .arg(utmZone)
            .arg(easting,0,'f',2)
            .arg(northing,0,'f',2)
        );
}

void MainWindow::ViewShowMap(QNetworkReply *reply)
{
    if(reply->error()==QNetworkReply::NoError){
        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());
        if(!pixmap.isNull()){
            ui->graphicsView->scene()->clear();
            ui->graphicsView->scene()->addItem(new QGraphicsPixmapItem(pixmap));
            ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);
        }
        else{
            QMessageBox::critical(this, "Error", "Error image");
        }
    }
    else{
        QMessageBox::critical(this, "Error", QString("Not found url: %1").arg(reply->url().toString()));
    }
}
