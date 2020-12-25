#include "pantalla.h"
#include "estructuras.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    cout << INT_MAX << endl;

    Persona * p1 = new Persona(1000);
    Persona * p2 = new Persona(2000);
    Persona * p3 = new Persona(3500);
    Persona * p4 = new Persona(3000);
    ListaPersonas * lista = new ListaPersonas;
    cout << "PRIMERA VEZ " << lista->isInList(p1) << endl;
    lista->insert(p1);
    cout << "SEGUNDA VEZ " <<lista->isInList(p1) << endl;
    lista->insertSort(p2);
    lista->insertSort(p3);
    lista->insertSort(p4);
    cout << "P: " << lista->primerNodo->persona->id << " U: " << lista->ultimoNodo->persona->id<<endl;

    QApplication a(argc, argv);
    pantalla w;
    w.show();
    return a.exec();
}
