#include "estructuras.h"

NodoAcciones::NodoAcciones(string dato){
    this->dato = dato;
    this->cantidad = 0;
    anterior = siguiente = NULL;
}

ListaAcciones::ListaAcciones(){
    primerNodo = ultimoNodo = NULL;
}

bool ListaAcciones::isEmpty(){
    return primerNodo == NULL;
}

void ListaAcciones::insert(string dato){
    NodoAcciones * nodo = new NodoAcciones(dato);

    if (primerNodo == NULL){
        primerNodo = ultimoNodo = nodo;
    }else{
        ultimoNodo->siguiente = nodo;
        nodo->anterior = ultimoNodo;
        ultimoNodo = nodo;
    }
}

int ListaAcciones::size(){
    int size = 0;
    NodoAcciones * tmp = primerNodo;
    while (tmp != NULL){
        size++;
        tmp = tmp->siguiente;
    }
    return size;
}

NodoAcciones * ListaAcciones::returnIndex(int n){
    if (n >= size()){
        return NULL;
    }
    NodoAcciones * tmp = primerNodo;
    for (int i = 0; i < n; i++){
        tmp = tmp->siguiente;
    }
    return tmp;
}
