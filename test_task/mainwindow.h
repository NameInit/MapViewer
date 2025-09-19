#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPointF>
#include <QMouseEvent>
#include "myscene.h"
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;
    MyScene *myScene;

private:
    void __WGS84toUTM(double lat, double lon, double &easting, double &northing, QString &zone);
    void __CalcWGS84(const QPointF &scenePos, double &lat, double &lon);
    void __GetTiles(int &xtile, int &ytile);

private slots:
    void ViewShowMap(QNetworkReply *reply);
    void ButtonShowMap();
    void ShowCoords(const QPointF &scenePos);
};
#endif // MAINWINDOW_H
