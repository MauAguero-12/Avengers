#include "pantalla.h"
#include "estructuras.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    cout << INT_MAX << endl;


    QApplication a(argc, argv);
    pantalla w;
    w.show();
    return a.exec();
}
