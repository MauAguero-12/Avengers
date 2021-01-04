#include "estructuras.h"

Persona::Persona(int id){
    this->id = id;

    pecados = new ListaAcciones();
    buenasAcciones = new ListaAcciones();
    amigos = new ListaPersonas();
    hijos = new ListaPersonas();
    paises = new Lista();
    deportes = new Lista();
    vidaMuerte = new Lista();
    padre = NULL;
    madre = NULL;
    vivo = true;
    parejaAsignada = false;
    hijosAsignados = false;
    hijo = false;

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

void Persona::printPerson(){
    cout << nombre << " "  << apellido << " " << id << endl;
    cout << "Fecha de nacimiento: " << diaNacimiento << "/" << mesNacimiento << "/" << fechaNacimiento << endl;
    cout << "Pais: " << pais << " | " << "Continente: " << continente << endl;
    cout << "Grupo Etario: " << grupoEtario << endl;
    if (vivo)
        cout << "Estado: VIVO" << endl;
    else
        cout << "Estado: MUERTO" << endl;
    buenasAcciones->printList();
    pecados->printList();
    deportes->printList();
    paises->printList();
    vidaMuerte->printList();
    cout << "\n" << endl;
}

bool Persona::sport(string deporte){
    for (int i = 0; i < deportes->size(); i++){
        if (deportes->returnIndex(i)->dato == deporte){
            return true;
        }
    }
    return false;
}

void Persona::assignAgeGroup(){
    if (edad < 2){
        grupoEtario = "Infantil";
    }else if (edad < 5){
        grupoEtario = "Pre-escolar";
    }else if (edad < 11){
        grupoEtario = "Escolar";
    }else if (edad < 15){
        grupoEtario = "Pubertad";
    }else if (edad < 20){
        grupoEtario = "Adolescencia";
    }else if (edad < 25){
        grupoEtario = "Joven";
    }else if (edad < 35){
        grupoEtario = "Adulto Joven";
    }else if (edad < 65){
        grupoEtario = "Adulto Maduro";
    }else{
        grupoEtario = "Adulto Mayor";
    }
}


void Persona::Ironman(){
    if (!vivo){
        vivo = true;
        vidaMuerte->insert("La persona fue salvada por Ironman");
    }
    if (padre != NULL){
        padre->Ironman();
    }
    if (madre != NULL){
        madre->Ironman();
    }
    for (int i = 0; i < hijos->size(); i++){
        hijos->returnIndex(i)->persona->Ironman();
    }
}

void Persona::Thor(){
    if (!vivo){
        vivo = true;
        vidaMuerte->insert("La persona fue salvada por Thor");
    }
}
