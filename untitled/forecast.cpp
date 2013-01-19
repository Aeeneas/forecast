#include "forecast.h"
#include "ui_forecast.h"

forecast::forecast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forecast)
{

    QHBoxLayout *layout = new QHBoxLayout();
    QPushButton *forecast = new QPushButton("take weather");
    text1 = new QTextEdit("ff");
    layout->addWidget(forecast);
    layout->addWidget(text1);
    setLayout(layout);
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
   connect(forecast, SIGNAL(clicked()), this, SLOT(takeWeather()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadFinished(QNetworkReply*)));
}

void forecast::takeWeather()
{

    manager->get(QNetworkRequest(QUrl("http://api.wunderground.com/api/7817a00b9094b04f/forecast/lang:RU/q/RU/Nizhniy_Novgorod.xml")));

}

void forecast::loadFinished(QNetworkReply *reply)
{
    QString answer;
    switch (reply->error())
       {
       case 0:
           answer = QString::fromUtf8(reply->readAll());
           text1->setText(answer);

           break;
       default:
           text1->setText("Ошибка загрузки");
           break;
        }
    reply->deleteLater();
    QDomDocument doc;
    doc.setContent(answer);
    QDomNodeList list1 = doc.elementsByTagName("celsius");
    QString forecast1=list1.at(1).toElement().text();
    //text1->setText(forecast1);
    qDebug()<<forecast1;

}




forecast::~forecast()
{
    delete ui;
}
