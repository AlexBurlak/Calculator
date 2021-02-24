#include "calculator.h"

#include <QApplication>
#include <QtCore>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.setWindowFlags(( Qt::Tool | Qt::CustomizeWindowHint ) |
                     ( Qt::WindowTitleHint | Qt::WindowSystemMenuHint |
                       Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint ));
    w.show();
    return a.exec();
}

