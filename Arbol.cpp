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
