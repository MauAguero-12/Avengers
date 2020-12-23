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
    
    Persona(int id);
    bool friendsInCommon(Persona * persona);
    void increaseSins();
    void increaseGoodActions();
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
    
};

class Mundo{
public:
    ListaPersonas * listaPersonas;
    
    
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
    void increaseSins();
    void increaseGoodActions();
    
    
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

};

#endif // ESTRUCTURAS_H

