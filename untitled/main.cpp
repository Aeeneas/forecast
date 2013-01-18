#include <QtGui/QApplication>
#include "forecast.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    forecast w;
    w.show();
    
    return a.exec();
}
