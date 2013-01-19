/********************************************************************************
** Form generated from reading UI file 'forecast.ui'
**
** Created: Sat 19. Jan 12:20:39 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORECAST_H
#define UI_FORECAST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_forecast
{
public:

    void setupUi(QWidget *forecast)
    {
        if (forecast->objectName().isEmpty())
            forecast->setObjectName(QString::fromUtf8("forecast"));
        forecast->resize(400, 300);

        retranslateUi(forecast);

        QMetaObject::connectSlotsByName(forecast);
    } // setupUi

    void retranslateUi(QWidget *forecast)
    {
        forecast->setWindowTitle(QApplication::translate("forecast", "forecast", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class forecast: public Ui_forecast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORECAST_H
