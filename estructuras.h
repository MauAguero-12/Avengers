#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include <unistd.h>
#include <cmath>

class Persona;
class ListaPersonas;
struct NodoPersona;
class Mundo;
struct NodoAcciones;
class ListaAcciones;
struct Nodo;
class Lista;
struct NodoArbol;
class Arbol;

class Persona{
public:
    int id;
    string nombre;
    string apellido;
    string genero;
    int fechaNacimiento;
    int mesNacimiento;
    int diaNacimiento;
    string grupoEtario;
    ListaAcciones * pecados;
    ListaAcciones * buenasAcciones;
    int edad;
    Lista * paises;
    ListaPersonas * amigos;
    string estadoMarital;
    ListaPersonas * hijos;
    Persona * conyuge;
    int ejercicio;
    Lista * deportes;
    string pais;
    string continente;
    Lista * vidaMuerte;
    bool vivo;
    
    Persona(int id);
    bool friendsInCommon(Persona * persona);
    void increaseSins();
    void increaseGoodActions();
    void printPerson();
};

struct NodoPersona{
public:
    Persona * persona;
    NodoPersona * siguiente;
    NodoPersona * anterior;
    
    NodoPersona(Persona * p);
};

class ListaPersonas{
public:
    NodoPersona * primerNodo;
    NodoPersona * ultimoNodo;
    
    ListaPersonas();
    bool isEmpty();
    void insertSort(Persona * p);
    int size();
    NodoPersona * returnIndex(int n);
    void insert(Persona * p);
    bool isInList(Persona * p);
    
};

class Mundo{
public:
    ListaPersonas * listaPersonas;
    Arbol * arbol;
    
    
    Mundo();
    int generateID();
    string generateName();
    string generateSurname();
    string generateGender();
    string generateCountry();
    string generateContinent();
    string generateReligion();
    string generateJob();
    Lista * generateCountryVisits();
    void generateFriends(Persona * p);
    ListaPersonas * generateKids();
    void createBirthdates();
    void increaseSins();
    void increaseGoodActions();
    Persona * findHuman(int id);
    void printHuman(int id);
    void printFamily(int id);
    void printFriendsOfFriends(int id);
    void findBySport();
    void stats();
    void printTree();
    
    
};

struct NodoAcciones{
    string dato;
    int cantidad;
    NodoAcciones * siguiente;
    NodoAcciones * anterior;

    NodoAcciones(string dato);
};

class ListaAcciones{
public:
    NodoAcciones * primerNodo;
    NodoAcciones * ultimoNodo;

    ListaAcciones();
    bool isEmpty();
    void insert(string);
    int size();
    NodoAcciones * returnIndex(int n);
    void printList();

};

struct Nodo{
    string dato;
    Nodo * siguiente;
    Nodo * anterior;

    Nodo(string dato);
};

class Lista{
public:
    Nodo * primerNodo;
    Nodo * ultimoNodo;

    Lista();
    bool isEmpty();
    void insert(string);
    int size();
    Nodo * returnIndex(int n);
    void printList();

};

struct NodoArbol{
public:
    NodoPersona * persona;
    NodoArbol * NodoIzquierdo;
    NodoArbol * NodoDerecho;

    NodoArbol();
    bool hoja();
};

class Arbol{
public:
    NodoArbol * raiz;

    Arbol();
};

#endif // ESTRUCTURAS_H

