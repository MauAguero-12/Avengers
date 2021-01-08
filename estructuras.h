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
class ListaPersonasRestringida;
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
    string profesion;
    string pais;
    string continente;
    string religion;

    int fechaNacimiento;
    int mesNacimiento;
    int diaNacimiento;
    string grupoEtario;
    int edad;

    ListaAcciones * pecados;
    ListaAcciones * buenasAcciones;
    int cantPecados;
    int cantBuenasAcciones;

    Lista * paises;

    ListaPersonas * amigos;

    string estadoMarital;
    Persona * padre;
    Persona * madre;
    Persona * conyuge;
    ListaPersonas * hijos;

    int ejercicio;
    Lista * deportes;

    Lista * vidaMuerte;
    bool vivo;

    bool parejaAsignada;
    bool hijosAsignados;
    bool hijo;
    
    Persona(int id);
    bool friendsInCommon(Persona * persona);
    void increaseSins();
    void increaseGoodActions();
    void printPerson();
    bool sport(string deporte);
    void generateAge(int a, int m, int d);
    void assignAgeGroup();

    void CorvusGlaive();
    void Midnight();
    void Nebula();
    void EbonyMaw();
    void BlackDwarf();
    void Thanos();

    void AntMan();
    void Ironman();
    void Thor();
    void Spiderman();
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

class ListaPersonasRestringida{
public:
    NodoPersona * primerNodo;
    NodoPersona * ultimoNodo;
    int max;

    ListaPersonasRestringida(int max);
    bool isEmpty();
    void insertSortMax(Persona * p);
    void insertSortMin(Persona * p);
    int size();
    //NodoPersona * returnIndex(int n);
    //bool isInList(Persona * p);

};

class Mundo{
public:
    ListaPersonas * listaPersonas;
    Arbol * arbol;

    int year;
    int mes;
    int dia;
    
    Mundo();
    void generateHumans(int cant);

    int generateID();
    string generateName();//cargar archivo
    string generateSurname();//cargar archivo
    string generateGender();
    string generateCountry();//cargar archivo
    string generateContinent();//cargar archivo
    string generateReligion();//cargar archivo
    string generateJob();//cargar archivo
    string generateMaritalState(Persona * p);
    void createBirthdates(ListaPersonas * lista);

    void increaseSins(ListaPersonas * lista);
    void increaseGoodActions(ListaPersonas * lista);

    Lista * generateCountryVisits();//cargar archivo
    Lista * generateSports(Persona *p);//cargar archivo
    void generateKids(Persona *p);
    void generateFriends(Persona * p);
    void generateCouple(Persona * p);

    void generateTree();//falta

    Persona * findHuman(int id);
    void printHuman(int id);
    void printFamily(int id);
    void printFriendsOfFriends(int id);
    void printBySport(string deporte);
    void stats();
    void printTree();//falta
    bool validateSon(Persona * padre, Persona * hijo);

    void CorvusGlaive();
    void Midnight();
    void Nebula();
    void EbonyMaw();
    void BlackDwarf();
    void Thanos();

    void AntMan();
    void Ironman();
    void Thor();
    void Spiderman();
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
    ListaPersonas * toList();
    ListaPersonas * levelToList(int n);
    int size();

private:
    void addAllToList(NodoArbol * p, ListaPersonas * lista);
    void addLevelToList(NodoArbol * p, ListaPersonas * lista, int nivel);
};

#endif // ESTRUCTURAS_H

