#include "forecast.h"
#include "ui_forecast.h"

forecast::forecast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forecast)
{
    QHBoxLayout *layout = new QHBoxLayout();
    QPushButton *forecast = new QPushButton("take weather");
    layout->addWidget(forecast);
    setLayout(layout);
    ui->setupUi(this);

    connect(forecast, SIGNAL(clicked()), this, SLOT(takeWeather()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadFinished(QNetworkReply*)));
}

void Widget::takeWeather()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://www.google.com/ig/api?weather=Moscow")));

}

void Widget::loadF


forecast::~forecast()
{
    delete ui;
}