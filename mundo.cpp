#include "estructuras.h"

Mundo::Mundo(){
    listaPersonas = new ListaPersonas();
}

int Mundo::generateID(){
    bool unique = true;
    int id;
    do{
        id = rand() % 10000000;
        
        for(int i = 0; i < listaPersonas->size(); i++){
            if (id == listaPersonas->returnIndex(i)->persona->id){
                unique = false;
                break;
            }
        }
    } while(!unique);
    return id;
}

string Mundo::generateName(){
    return "nombre";
}

string Mundo::generateSurname(){
    return "apellido";
}

string Mundo::generateGender(){
    int n = rand() % 100;
    if (n < 50)
        return "hombre";
    else
        return "mujer";
}

string Mundo::generateCountry(){
    return "pais";
}

string Mundo::generateContinent(){
    return "continente";
}

string Mundo::generateReligion(){
    return "religion";
}

string Mundo::generateJob(){
    return "trabajo";
}

void Mundo::generateFriends(Persona * p){
    int cant = rand() % 51;
    ListaPersonas * listaAmigos = new ListaPersonas();

    for (int i = 0; i < listaPersonas->size(); i++){
        if (cant == 0){
            break;
        }

        Persona * posAmigo = listaPersonas->returnIndex(i)->persona;

        bool restricciones = false;
        if (p->pais == posAmigo->pais){
            restricciones = true;
        } else{
            int extranjero = rand() % 100;
            if (p->friendsInCommon(posAmigo)){
                if (extranjero < 70){
                    restricciones = true;
                }
            } else{
                if (extranjero < 40){
                    restricciones = true;
                }
            }
        }

        if (restricciones){
            listaAmigos->insertSort(posAmigo);
        }
    }
    p->amigos = listaAmigos;
}

void Mundo::increaseSins(){
    NodoPersona * tmp = listaPersonas->primerNodo;
    while(tmp != NULL){
        tmp->persona->increaseSins();
        tmp = tmp->siguiente;
    }
}

void Mundo::increaseGoodActions(){
    NodoPersona * tmp = listaPersonas->primerNodo;
    while(tmp != NULL){
        tmp->persona->increaseGoodActions();
        tmp = tmp->siguiente;
    }
}