#ifndef VIEWER_H
#define VIEWER_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class Viewer;
}

class Viewer : public QDialog
{
    Q_OBJECT

public:
    explicit Viewer(QWidget *parent = nullptr, QString lat_=0, QString lon_=0, QString zoom_=0);
    ~Viewer();

private:
    Ui::Viewer *ui;
    QString lat;
    QString lon;
    QString zoom;
    QNetworkAccessManager *networkManager;

private slots:
    void showImage(QNetworkReply *reply);
};

#endif // VIEWER_H
