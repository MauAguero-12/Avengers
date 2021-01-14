#include "pantalla.h"
#include "estructuras.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand((unsigned) time(0));

    Mundo * m = new Mundo();
    time_t t = std::time(0);
    tm* now = localtime(&t);

    m->year = now->tm_year + 1900;
    m->mes = now->tm_mon + 1;
    m->dia = now->tm_mday;

    //cout << m->dia << "/" << m->mes << "/" << m->year<< endl;

    cout << "\n" << endl;
    /*m->generateHumans(100);
    cout << m->listaPersonas->size() << "\n" << endl;

    //for (int i = 0; i < m->listaPersonas->size(); i++){
        //m->listaPersonas->returnIndex(i)->persona->printPerson();
    //}

    m->printHuman(m->listaPersonas->primerNodo->persona->id);*/

    QApplication a(argc, argv);
    pantalla w;
    w.mundo = m;
    w.show();
    return a.exec();
}
