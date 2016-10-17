/********************************************************************************
** Form generated from reading UI file 'adplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADPLAYER_H
#define UI_ADPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adplayer
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *view_lb;
    QVBoxLayout *verticalLayout;
    QLabel *date_lb;
    QLabel *weatherlb;
    QLabel *time_lb;

    void setupUi(QMainWindow *Adplayer)
    {
        if (Adplayer->objectName().isEmpty())
            Adplayer->setObjectName(QStringLiteral("Adplayer"));
        Adplayer->resize(835, 454);
        centralWidget = new QWidget(Adplayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        view_lb = new QLabel(centralWidget);
        view_lb->setObjectName(QStringLiteral("view_lb"));
        view_lb->setMinimumSize(QSize(600, 0));
        view_lb->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(view_lb);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        date_lb = new QLabel(centralWidget);
        date_lb->setObjectName(QStringLiteral("date_lb"));
        date_lb->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));

        verticalLayout->addWidget(date_lb);

        weatherlb = new QLabel(centralWidget);
        weatherlb->setObjectName(QStringLiteral("weatherlb"));
        weatherlb->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));

        verticalLayout->addWidget(weatherlb);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        time_lb = new QLabel(centralWidget);
        time_lb->setObjectName(QStringLiteral("time_lb"));
        time_lb->setMaximumSize(QSize(16777215, 40));
        time_lb->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 127);"));

        verticalLayout_2->addWidget(time_lb);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        Adplayer->setCentralWidget(centralWidget);

        retranslateUi(Adplayer);

        QMetaObject::connectSlotsByName(Adplayer);
    } // setupUi

    void retranslateUi(QMainWindow *Adplayer)
    {
        Adplayer->setWindowTitle(QApplication::translate("Adplayer", "Adplayer", 0));
        view_lb->setText(QString());
        date_lb->setText(QApplication::translate("Adplayer", "2015-10-17 11:14", 0));
        weatherlb->setText(QApplication::translate("Adplayer", "\345\244\251\346\260\224\357\274\232\346\231\264\345\244\251", 0));
        time_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Adplayer: public Ui_Adplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADPLAYER_H
