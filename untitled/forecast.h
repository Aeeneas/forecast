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
#include <QPainter>
#include <QLabel>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QFontDatabase>

namespace Ui {
class forecast;
}

class forecast : public QWidget
{
    Q_OBJECT
    
public:
    explicit forecast(QWidget *parent = 0);
    ~forecast();
    QString parsingXML(QString);
    void drawPicture(QString);
    QGraphicsView view;
    QString tempNiz;


public slots:
   void takeWeather();
   void loadFinished(QNetworkReply*);
   void drawSlot();


private:
    Ui::forecast *ui;
    QNetworkAccessManager *manager;
    QTextEdit *text1;
};

#endif // FORECAST_H
