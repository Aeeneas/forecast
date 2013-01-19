#include "forecast.h"
#include "ui_forecast.h"

forecast::forecast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forecast)
{

    QHBoxLayout *layout = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout();

    QPushButton *forecast = new QPushButton("take weather");
    QPushButton *imageTake = new QPushButton("take image");
    vLayout->addWidget(forecast);
    vLayout->addWidget(imageTake);

    text1 = new QTextEdit("ff");
    layout->addLayout(vLayout);
    layout->addWidget(forecast);

    //layout->addWidget(text1);
    layout->addWidget(&view);
    setLayout(layout);
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(forecast, SIGNAL(clicked()), this, SLOT(takeWeather()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadFinished(QNetworkReply*)));
    connect(imageTake,SIGNAL(clicked()),this,SLOT(drawSlot()));

}

void forecast::takeWeather()
{

    manager->get(QNetworkRequest(QUrl("http://api.wunderground.com/api/7817a00b9094b04f/forecast/lang:RU/q/RU/Nizhniy_Novgorod.xml")));

}

void forecast::drawSlot()
{
    drawPicture(tempNiz);
}

void forecast::loadFinished(QNetworkReply *reply)
{
    QString answer;
    switch (reply->error())
       {
       case 0:
           answer = QString::fromUtf8(reply->readAll());
           text1->setText(answer);
           qDebug()<<parsingXML(answer);

           break;
       default:
           text1->setText("Ошибка загрузки");
           break;
        }
    reply->deleteLater();

}

QString forecast::parsingXML(QString answer)
{
    QDomDocument doc;
    doc.setContent(answer);
    QDomNodeList list1 = doc.elementsByTagName("celsius");
    QString tempString1=list1.at(1).toElement().text();
    QString tempString2=list1.at(2).toElement().text();
    tempNiz = tempString1+"..."+tempString2;
    return tempString1;

}

void forecast::drawPicture(QString tempNiz)
{
QImage image("image.png");
// tell the painter to draw on the QImage
QPainter* painter = new QPainter(&image); // sorry i forgot the "&"
QColor color;
color.setRgb(153,0,0);
painter->setPen(color);
int fontId = QFontDatabase::addApplicationFont("Magistral Bold.TTF");
if (fontId == 0){
    QFont font(QFontDatabase::applicationFontFamilies(fontId).first());
    font.setPointSize(72);
    painter->setFont(font);
}
// you probably want the to draw the text to the rect of the image
painter->drawText(677,280, tempNiz);

QLabel* imageLabel = new QLabel();
imageLabel->setPixmap(QPixmap::fromImage(image));
imageLabel->setAlignment(Qt::AlignCenter);

QGraphicsScene *scene = new QGraphicsScene;
scene->addPixmap(QPixmap::fromImage(image));
//scene.addText("test");
view.setScene(scene);
qDebug()<<tempNiz;
}


forecast::~forecast()
{
    delete ui;
}
