/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_main;
    QLabel *label_lon;
    QLineEdit *lineEdit_lat;
    QLabel *label_wgs84;
    QLabel *label_zoom;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit_zoom;
    QPushButton *pushButton_show;
    QLabel *label_lat;
    QLineEdit *lineEdit_lon;
    QLabel *label_utm;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 0, 451, 541));
        gridLayout_main = new QGridLayout(gridLayoutWidget);
        gridLayout_main->setObjectName("gridLayout_main");
        gridLayout_main->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout_main->setContentsMargins(0, 0, 0, 0);
        label_lon = new QLabel(gridLayoutWidget);
        label_lon->setObjectName("label_lon");
        label_lon->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_main->addWidget(label_lon, 2, 0, 1, 1);

        lineEdit_lat = new QLineEdit(gridLayoutWidget);
        lineEdit_lat->setObjectName("lineEdit_lat");
        lineEdit_lat->setStyleSheet(QString::fromUtf8("color: black; background: white;"));

        gridLayout_main->addWidget(lineEdit_lat, 1, 1, 1, 1);

        label_wgs84 = new QLabel(gridLayoutWidget);
        label_wgs84->setObjectName("label_wgs84");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_wgs84->sizePolicy().hasHeightForWidth());
        label_wgs84->setSizePolicy(sizePolicy);

        gridLayout_main->addWidget(label_wgs84, 6, 1, 1, 1);

        label_zoom = new QLabel(gridLayoutWidget);
        label_zoom->setObjectName("label_zoom");
        label_zoom->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_main->addWidget(label_zoom, 3, 0, 1, 1);

        graphicsView = new QGraphicsView(gridLayoutWidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMaximumSize(QSize(400, 400));
        graphicsView->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        graphicsView->setStyleSheet(QString::fromUtf8("border: 2px solid #FF0000;\n"
"background-color: #f0f0f0;"));

        gridLayout_main->addWidget(graphicsView, 5, 1, 1, 1);

        lineEdit_zoom = new QLineEdit(gridLayoutWidget);
        lineEdit_zoom->setObjectName("lineEdit_zoom");
        lineEdit_zoom->setStyleSheet(QString::fromUtf8("color: black; background: white;"));

        gridLayout_main->addWidget(lineEdit_zoom, 3, 1, 1, 1);

        pushButton_show = new QPushButton(gridLayoutWidget);
        pushButton_show->setObjectName("pushButton_show");

        gridLayout_main->addWidget(pushButton_show, 4, 1, 1, 1);

        label_lat = new QLabel(gridLayoutWidget);
        label_lat->setObjectName("label_lat");
        label_lat->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_main->addWidget(label_lat, 1, 0, 1, 1);

        lineEdit_lon = new QLineEdit(gridLayoutWidget);
        lineEdit_lon->setObjectName("lineEdit_lon");
        lineEdit_lon->setStyleSheet(QString::fromUtf8("color: black; background: white;"));

        gridLayout_main->addWidget(lineEdit_lon, 2, 1, 1, 1);

        label_utm = new QLabel(gridLayoutWidget);
        label_utm->setObjectName("label_utm");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_utm->sizePolicy().hasHeightForWidth());
        label_utm->setSizePolicy(sizePolicy2);

        gridLayout_main->addWidget(label_utm, 7, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_lon->setText(QCoreApplication::translate("MainWindow", " Lon", nullptr));
        lineEdit_lat->setText(QString());
        label_wgs84->setText(QCoreApplication::translate("MainWindow", "WGS84 (0;0)", nullptr));
        label_zoom->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        pushButton_show->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        label_lat->setText(QCoreApplication::translate("MainWindow", " Lat", nullptr));
        label_utm->setText(QCoreApplication::translate("MainWindow", "UTM 0 (0;0)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
