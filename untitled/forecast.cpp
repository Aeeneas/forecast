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
    loop = new QEventLoop();
    layout->addWidget(&view);
    setLayout(layout);
    ui->setupUi(this);


    manager = new QNetworkAccessManager(this);
    connect(forecast, SIGNAL(clicked()), this, SLOT(takeWeather()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadFinished(QNetworkReply*)));
    connect(imageTake,SIGNAL(clicked()),this,SLOT(drawSlot()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), loop, SLOT(quit()));

}

void forecast::takeWeather()
{
    counter=0;
    QStringList adress;
    QString str;
    adress<<"http://api.wunderground.com/api/7817a00b9094b04f/forecast/lang:RU/q/RU/Diveyevo.xml"<<"http://api.wunderground.com/api/7817a00b9094b04f/forecast/lang:RU/q/RU/Nizhniy_Novgorod.xml"<<"http://api.wunderground.com/api/7817a00b9094b04f/forecast/lang:RU/q/RU/Moscow.xml";
    foreach(str, adress)
    {
        manager->get(QNetworkRequest(QUrl(str)));
        loop->exec();
        counter++;
     }


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

QStringList forecast::parsingXML(QString answer)
{
    QDomDocument doc;
    doc.setContent(answer);
    QDomNodeList list1 = doc.elementsByTagName("celsius");
    QDomNodeList icons = doc.elementsByTagName("icon");
    tempList<<list1.at(1).toElement().text()<<list1.at(2).toElement().text()<<icons.at(1).toElement().text();
    return tempList;
}

void forecast::drawPicture(QString tempNiz)
{
QImage image("image.png");
QImage icon1("icon/"+tempList[2]+".gif");
QImage icon2("icon/"+tempList[5]+".gif");
QImage icon3("icon/"+tempList[8]+".gif");
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
painter->drawText(677,250, tempList[0]+".."+ tempList[1]);
painter->drawText(677,380, tempList[3]+".."+ tempList[4]);
painter->drawText(677,480, tempList[6]+".."+ tempList[7]);
painter->drawImage(573, 250, icon1);
painter->drawImage(573, 350, icon2);
painter->drawImage(573, 450, icon3);

/*QLabel* imageLabel = new QLabel();
imageLabel->setPixmap(QPixmap::fromImage(image));
imageLabel->setAlignment(Qt::AlignCenter);*/

QGraphicsScene *scene = new QGraphicsScene;
scene->addPixmap(QPixmap::fromImage(image));
//scene.addText("test");
view.setScene(scene);
QString out;

foreach(out, tempList){

    qDebug()<<out;
}
image.save("out.png", "PNG");

}


forecast::~forecast()
{
    delete ui;
}
