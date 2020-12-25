#include "estructuras.h"

Mundo::Mundo(){
    listaPersonas = new ListaPersonas();
    arbol = new Arbol();
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

ListaPersonas * Mundo::generateKids(){
    return NULL;
}

void Mundo::createBirthdates(){
    NodoPersona * tmp = listaPersonas->primerNodo;
    while (tmp != NULL){
        Persona * p = tmp->persona;
        p->fechaNacimiento = rand() % 81 + 1940;
        p->mesNacimiento = rand() % 12 + 1;
        if (p->mesNacimiento == 2){
            if (p->fechaNacimiento % 4 == 0){
                p->diaNacimiento  = rand() % 29 + 1;
            } else{
                p->diaNacimiento  = rand() % 28 + 1;
            }
        } else if (p->mesNacimiento == 4 || p->mesNacimiento == 6 || p->mesNacimiento == 9 || p->mesNacimiento == 11){
            p->diaNacimiento  = rand() % 30 + 1;
        } else{
            p->diaNacimiento  = rand() % 31 + 1;
        }
        //añadir edad
        //añadir grupo etario
        tmp = tmp->siguiente;
    }
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

Persona * Mundo::findHuman(int id){
    NodoArbol * tmpA = arbol->raiz;
    NodoPersona * persona = tmpA->persona;

    while (!tmpA->hoja()){
        if (tmpA->persona->persona->id == id){
            persona = tmpA->persona;
            break;
        } else if (tmpA->persona->persona->id >= id){
            tmpA = tmpA->NodoDerecho;
            if (tmpA->hoja()){
                persona = tmpA->persona;
            }
        } else{
            tmpA = tmpA->NodoIzquierdo;
            if (tmpA->hoja()){
                persona = tmpA->persona;
            }
        }
    }

    if (persona->persona->id < id){
        while (persona->persona->id < id){
            persona = persona->siguiente;
        }
    } else if (persona->persona->id > id){
        while (persona->persona->id > id){
            persona = persona->anterior;
        }
    }

    if (persona->persona->id == id){
        return persona->persona;
    } else{
        return NULL;
    }

}

void Mundo::printHuman(int id){
    Persona * p = findHuman(id);
    p->printPerson();
}

void Mundo::printFamily(int id){
    Persona * p = findHuman(id);
    if (p != NULL){
        if (p->conyuge != NULL){
            cout << "CONYUGE\n" << endl;
            p->conyuge->printPerson();
        }
        if (p->hijos->size() != 0){
            cout << "HIJOS\n" << endl;
        }
        for (int i = 0; i < p->hijos->size(); i++){
            p->hijos->returnIndex(i)->persona->printPerson();
        }
    }
}

void Mundo::printFriendsOfFriends(int id){
    Persona * p = findHuman(id);
    if (p != NULL){
        ListaPersonas * lista = new ListaPersonas();
        for (int i = 0; i < p->amigos->size(); i++){
            NodoPersona * amigo = p->amigos->returnIndex(i);
            ListaPersonas * amigosDeAmigo = amigo->persona->amigos;
            for (int j = 0; amigosDeAmigo->size(); i++){
                NodoPersona * amigoDeAmigo = amigosDeAmigo->returnIndex(j);
                lista->insert(amigoDeAmigo->persona);
            }
        }

        for(int i = 0; i < lista->size(); i++){
            lista->returnIndex(i)->persona->printPerson();
        }
    }
}

void Mundo::printBySport(string deporte){
    NodoPersona * nodo = listaPersonas->primerNodo;
    while(nodo != NULL){
        if(nodo->persona->sport(deporte)){
            nodo->persona->printPerson();
        }
        nodo = nodo->siguiente;
    }
}
