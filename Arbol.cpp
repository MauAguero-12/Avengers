#include "estructuras.h"

NodoArbol::NodoArbol(){
    NodoDerecho = NodoIzquierdo = NULL;
}

bool NodoArbol::hoja(){
    return NodoIzquierdo == NULL && NodoDerecho == NULL;
}


Arbol::Arbol(){
    raiz = NULL;
}

int Arbol::size(){
    int n = -1;
    NodoArbol * nodo = raiz;
    while (nodo != NULL){
        nodo = nodo->NodoIzquierdo;
        n++;
    }
    return n;
}

ListaPersonas * Arbol::toList(){
    ListaPersonas * lista = new ListaPersonas();
    addAllToList(raiz, lista);
    return lista;
}

void Arbol::addAllToList(NodoArbol *p, ListaPersonas *lista){
    if (p != NULL){
        lista->insert(p->persona->persona);
        addAllToList(p->NodoIzquierdo, lista);
        addAllToList(p->NodoDerecho, lista);
    }
}

ListaPersonas * Arbol::levelToList(int n){
    ListaPersonas * lista = new ListaPersonas();
    addLevelToList(raiz, lista, n);
    return lista;
}

void Arbol::addLevelToList(NodoArbol * p, ListaPersonas * lista, int nivel){
    if (nivel == 0){
        lista->insert(p->persona->persona);
    } else{
        addLevelToList(p->NodoIzquierdo, lista, nivel - 1);
        addLevelToList(p->NodoDerecho, lista, nivel - 1);
    }
}
