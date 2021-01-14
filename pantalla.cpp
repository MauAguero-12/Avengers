#include "pantalla.h"
#include "ui_pantalla.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QString>

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
     string msj = "Se han generado " + to_string(cantHumanos) + " humanos";
     QString msj2 = QString::fromStdString(msj);
     QMessageBox::information(this, "", msj2);
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
    }  catch (...){
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

    string msj = "Corvus Glaive ha eliminado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnMidnight_clicked()
{
    mundo->Midnight();
    string msj = "Midnight ha eliminado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnNebula_clicked()
{
    //mundo->Nebula();
    string msj = "Nebula ha eliminado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnEbonyMaw_clicked()
{
    //mundo->EbonyMaw();
    string msj = "Ebony Maw ha eliminado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}


void pantalla::on_btnBlackDwarf_clicked()
{
    //mundo->BlackDwarf();
    string msj = "Black Dwarf ha eliminado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnThanos_clicked()
{
    //mundo->Thanos();
    string msj = "Thanos ha eliminado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnConsultaVillanos_clicked()
{

}



void pantalla::on_btnAntMan_clicked()
{
    //mundo->AntMan();
    string msj = "Ant Man ha salvado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnIronMan_clicked()
{
    mundo->Ironman();
    string msj = "Ironman ha salvado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnThor_clicked()
{
    mundo->Thor();
    string msj = "Thor ha salvado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnSpiderman_clicked()
{
    //mundo->Spiderman();
    string msj = "Spiderman ha salvado una parte de los humanos";
    QString msj2 = QString::fromStdString(msj);
    QMessageBox::information(this, "", msj2);
}

void pantalla::on_btnConsultarVengadores_clicked()
{

}


void pantalla::on_btnConsultarDeporte_clicked()
{
    string deporte = ui->cbxDeporte->currentText().toUtf8().constData();
    mundo->printBySport(deporte);
}
