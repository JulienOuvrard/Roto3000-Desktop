#include "welcome.h"
#include <QApplication>
#include <QtGui>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Welcome welcome;
    welcome.show();

    return a.exec();
}
