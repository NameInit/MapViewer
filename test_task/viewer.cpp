#include "viewer.h"
#include "ui_viewer.h"

Viewer::Viewer(QWidget *parent, QString lat_, QString lon_, QString zoom_)
    : QDialog(parent)
    , ui(new Ui::Viewer), lat(lat_), lon(lon_), zoom(zoom_)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    ui->label_lat_edit->setText(lat);
    ui->label_lon_edit->setText(lon);
    ui->label_zoom_edit->setText(zoom);
}

Viewer::~Viewer()
{
    delete ui;
}

void Viewer::showImage(QNetworkReply *reply)
{
    ;
}
