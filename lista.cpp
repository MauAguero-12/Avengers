#include "estructuras.h"

Nodo::Nodo(string dato){
    this->dato = dato;
    anterior = NULL;
    siguiente = NULL;
}

Lista::Lista(){
    primerNodo = NULL;
    ultimoNodo = NULL;
}

bool Lista::isEmpty(){
    return primerNodo == NULL;
}

void Lista::insert(string dato){
    Nodo * nodo = new Nodo(dato);

    if (primerNodo == NULL){
        primerNodo = ultimoNodo = nodo;
    }else{
        ultimoNodo->siguiente = nodo;
        nodo->anterior = ultimoNodo;
        ultimoNodo = nodo;
    }
}

int Lista::size(){
    int size = 0;
    Nodo * tmp = primerNodo;
    while (tmp != NULL){
        size++;
        tmp = tmp->siguiente;
    }
    return size;
}

Nodo * Lista::returnIndex(int n){
    if (n >= size()){
        return NULL;
    }
    Nodo * tmp = primerNodo;
    for (int i = 0; i < n; i++){
        tmp = tmp->siguiente;
    }
    return tmp;
}

void Lista::printList(){
    Nodo * nodo = primerNodo;
    if (nodo == NULL){
        cout << "" << endl;
    }
    while (nodo != NULL){
        cout << nodo->dato;
        if (nodo->siguiente == NULL){
            cout << "" << endl;
        } else{
            cout << " | ";
        }
        nodo = nodo->siguiente;
    }
}

bool Lista::isInList(string dato){
    Nodo * nodo = primerNodo;

    while (nodo != NULL){
        if (nodo->dato == dato){
            return true;
        } else{
            nodo = nodo->siguiente;
        }
    }
    return false;
}
