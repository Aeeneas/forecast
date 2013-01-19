#ifndef FORECAST_H
#define FORECAST_H
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QTextEdit>
#include <QtXml>
#include <QtXmlPatterns/QtXmlPatterns>
#include <QDomElement>
#include <qdom.h>
//#include <xmlsyntaxhighlighter.h>

namespace Ui {
class forecast;
}

class forecast : public QWidget
{
    Q_OBJECT
    
public:
    explicit forecast(QWidget *parent = 0);
    ~forecast();

public slots:
   void takeWeather();
   void loadFinished(QNetworkReply*);

private:
    Ui::forecast *ui;
    QNetworkAccessManager *manager;
    QTextEdit *text1;
};

#endif // FORECAST_H
