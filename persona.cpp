#include "estructuras.h"

Persona::Persona(int id){
    this->id = id;

    pecados = new ListaAcciones();
    buenasAcciones = new ListaAcciones();
    amigos = new ListaPersonas();
    hijos = new ListaPersonas();
    paises = new Lista();
    deportes = new Lista();

    pecados->insert("Lujuria");
    pecados->insert("Gula");
    pecados->insert("Avaricia");
    pecados->insert("Pereza");
    pecados->insert("Ira");
    pecados->insert("Envidia");
    pecados->insert("Soberbia");

    buenasAcciones->insert("Castidad");
    buenasAcciones->insert("Ayuno");
    buenasAcciones->insert("Donacion");
    buenasAcciones->insert("Diligencia");
    buenasAcciones->insert("Calma");
    buenasAcciones->insert("Solidaridad");
    buenasAcciones->insert("Humildad");

}

bool Persona::friendsInCommon(Persona *persona){
    bool comun = false;
    for (int i = 0; i < persona->amigos->size(); i++){
        if (comun){
            break;
        }
        for (int j = 0; j < amigos->size(); j++){
            if (persona->amigos->returnIndex(i)->persona == amigos->returnIndex(j)->persona){
                comun = true;
                break;
            }
        }
    }
    return comun;
}


void Persona::increaseSins(){
    for (int i = 0; i < pecados->size(); i++){
        pecados->returnIndex(i)->cantidad += rand() % 101;
    }
}

void Persona::increaseGoodActions(){
    for (int i = 0; i < buenasAcciones->size(); i++){
        buenasAcciones->returnIndex(i)->cantidad += rand() % 101;
    }
}
