#ifndef FORECAST_H
#define FORECAST_H
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

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
};

#endif // FORECAST_H
