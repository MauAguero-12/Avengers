#include "pantalla.h"
#include "ui_pantalla.h"

pantalla::pantalla(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pantalla)
{
    ui->setupUi(this);
}

pantalla::~pantalla()
{
    delete ui;
}
void pantalla::on_btnGenerarHumanos_clicked()
{
     int cantHumanos = stoi(ui->txfGenerarHumanos->text().toUtf8().constData());
     mundo->generateHumans(cantHumanos);
}

void pantalla::on_btnConsultar_clicked()
{
    //NodoPersona * nodo = mundo->listaPersonas->primerNodo;
    //while (nodo != NULL){
        //nodo->persona->printPerson();
        //nodo = nodo->siguiente;
    //}

    try {
        int id = stoi(ui->txfConsultaID->text().toUtf8().constData());
        if (ui->rbtnConsultaID->isChecked()){
            mundo->printHuman(id);
        } else if (ui->rbtnConsultaFamilia->isChecked()){
            mundo->printFamily(id);
        } else if (ui->rbtnConsultaAmigosAmigos->isChecked()){
            mundo->printFriendsOfFriends(id);
        } else{
            NodoPersona * nodo = mundo->listaPersonas->primerNodo;
            while (nodo != NULL){
                nodo->persona->printPerson();
                nodo = nodo->siguiente;
            }
        }
    }  catch (exception e){
        cout << "ERROR" << endl;
    }

}

void pantalla::on_btnConsultarHumanos_clicked()
{
    mundo->stats();
}

void pantalla::on_btnImprimirArbol_clicked()
{
    //mundo->printTree();
}

void pantalla::on_btnCorvusGlaive_clicked()
{
    mundo->CorvusGlaive();
}

void pantalla::on_btnMidnight_clicked()
{
    mundo->Midnight();
}

void pantalla::on_btnNebula_clicked()
{
    //mundo->Nebula();
}

void pantalla::on_btnEbonyMaw_clicked()
{
    //mundo->EbonyMaw();
}

void pantalla::on_btnBlackDwarf_clicked()
{
    //mundo->BlackDwarf();
}

void pantalla::on_btnThanos_clicked()
{
    //mundo->Thanos();
}

void pantalla::on_btnConsultaVillanos_clicked()
{

}



void pantalla::on_btnAntMan_clicked()
{
    //mundo->AntMan();
}

void pantalla::on_btnIronMan_clicked()
{
    mundo->Ironman();
}

void pantalla::on_btnThor_clicked()
{
    mundo->Thor();
}

void pantalla::on_btnSpiderman_clicked()
{
    //mundo->Spiderman();
}

void pantalla::on_btnConsultarVengadores_clicked()
{

}


void pantalla::on_btnConsultarDeporte_clicked()
{
    string deporte = ui->cbxDeporte->currentText().toUtf8().constData();
    mundo->printBySport(deporte);
}
