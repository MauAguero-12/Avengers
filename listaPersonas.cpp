#include "estructuras.h"

NodoPersona::NodoPersona(Persona * p){
    persona = p;
    anterior = siguiente = NULL;
}

ListaPersonas::ListaPersonas(){
    primerNodo = ultimoNodo = NULL;
}

bool ListaPersonas::isEmpty(){
    return primerNodo == NULL;
}

void ListaPersonas::insertSort(Persona *p){
    NodoPersona * nodo = new NodoPersona(p);

    if (primerNodo == NULL){
        primerNodo = nodo;
        ultimoNodo = nodo;
    }else{
        if (primerNodo->persona->id > p->id){
            nodo->siguiente = primerNodo;
            primerNodo->anterior = nodo;
            primerNodo = nodo;
        } else if (ultimoNodo->persona->id < p->id){
            ultimoNodo->siguiente = nodo;
            nodo->anterior = ultimoNodo;
            ultimoNodo = nodo;
        } else{
            NodoPersona * tmp = primerNodo;
            while (tmp->persona->id < p->id){
                tmp = tmp->siguiente;
            }
            tmp->anterior->siguiente = nodo;
            nodo->anterior = tmp->anterior;
            nodo->siguiente = tmp;
            tmp->anterior = nodo;
        }
        }
}

int ListaPersonas::size(){
    int size = 0;
    NodoPersona * tmp = primerNodo;
    while (tmp != NULL){
        size++;
        tmp = tmp->siguiente;
    }
    return size;
}

NodoPersona * ListaPersonas::returnIndex(int n){
    if (n >= size()){
        return NULL;
    }
    NodoPersona * tmp = primerNodo;
    for (int i = 0; i < n; i++){
        tmp = tmp->siguiente;
    }
    return tmp;
}

void ListaPersonas::insert(Persona *p){
    if (!isInList(p)){
        NodoPersona * nodo = new NodoPersona(p);
        if (primerNodo == NULL){
            primerNodo = nodo;
            ultimoNodo = nodo;
        } else{
            ultimoNodo->siguiente = nodo;
            nodo->anterior = ultimoNodo;
            ultimoNodo = nodo;
        }
    }
}

bool ListaPersonas::isInList(Persona *p){
    NodoPersona * tmp = primerNodo;
    while (tmp != NULL){
        if (tmp->persona == p){
            return true;
        }
        tmp = tmp->siguiente;
    }
    return false;
}
