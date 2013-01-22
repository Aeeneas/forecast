#include <QtGui/QApplication>
#include "forecast.h"
#include "QTextCodec"

int main(int argc, char *argv[])
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251")); //eciaiaiey
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("CP1251")); //eciaiaiey
    QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251")); //eciaiaiey
    QApplication a(argc, argv);
    forecast w;
    w.show();
    
    return a.exec();
}
