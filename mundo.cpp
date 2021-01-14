#include "estructuras.h"

Mundo::Mundo(){
    listaPersonas = new ListaPersonas();
    arbol = new Arbol();
}

void Mundo::generateHumans(int cant){
    ListaPersonas * lista = new ListaPersonas();
    for (int i = 0; i < cant; i++){
        Persona * p = new Persona(generateID());

        p->genero = generateGender();
        if (p->genero == "Hombre"){
            p->nombre = generateMaleName();
        } else{
            p->nombre = generateFemaleName();
        }
        p->apellido = generateSurname();
        p->pais = generateCountry();
        p->continente = generateContinent();
        generateCountryVisits(p);
        p->estadoMarital = generateMaritalState(p);
        p->ejercicio = rand() % 8;
        p->deportes = generateSports(p);
        p->religion = generateReligion();
        p->profesion = generateJob();
        lista->insert(p);
    }
    //cout << "PRIMERA PARTE" << endl;

    createBirthdates(lista);
    increaseGoodActions(lista);
    increaseSins(lista);

    //cout << "SEGUNDA PARTE" << endl;

    for (int i = 0; i < cant; i++){
        Persona * p = lista->returnIndex(i)->persona;
        listaPersonas->insertSort(p);
    }

    //cout << "TERCERA PARTE" << endl;

    for (int i = 0; i < cant; i++){
        Persona * p = lista->returnIndex(i)->persona;
        generateFriends(p);
        generateCouple(p);

    }

    //cout << "CUARTA PARTE" << endl;

    for (int i = 0; i < cant; i++){
        Persona * p = lista->returnIndex(i)->persona;
        generateKids(p);
    }

    delete lista;
    //cout << "QUINTA PARTE" << endl;

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

string Mundo::generateMaleName(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Nombres-Hombre.txt");
    string linea;

    int contador = 0;
    int max = rand()%51;

    while(getline(archivo_nombre, linea)){
        if(max == contador){
            break;
        }
        contador++;
    }
    return linea;
}

string Mundo::generateFemaleName(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Nombres-Mujeres.txt");
    string linea;

    int contador = 0;
    int max = rand()%51;

    while(getline(archivo_nombre, linea)){
        if(max == contador) {
            break;
        }
        contador++;
    }
    return linea;
}

string Mundo::generateSurname(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Apellidos.txt");
    string linea;

    int contador = 0;
    int max = rand()%91;

    while(getline(archivo_nombre, linea)){
        if(max == contador){
            break;
        }
        contador++;
    }
    return linea;
}

string Mundo::generateGender(){
    int n = rand() % 100;
    if (n < 50)
        return "Hombre";
    else
        return "Mujer";
}

string  Mundo::generateCountry(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Paises.txt");
    string linea;

    int contador = 0;
    int max = rand()%180;

    while(getline(archivo_nombre, linea)){
        if(max == contador){
            break;
        }
        contador++;
    }
    return linea;
}

string Mundo::generateContinent(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Continentes.txt");
    string linea;

    int contador = 0;
    int max = rand()%8;

    while(getline(archivo_nombre, linea)){
        if(max == contador){
            break;
        }
        contador++;
    }
    return linea;
}

string Mundo::generateReligion(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Religiones.txt");
    string linea;

    int contador = 0;
    int max = rand()%16;

    while(getline(archivo_nombre, linea)){
        if(max == contador){
            break;
        }
        contador++;
    }
    return linea;
}

string Mundo::generateJob(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Trabajos.txt");
    string linea;

    int contador = 0;
    int max = rand()%71;

    while(getline(archivo_nombre, linea)){
        if(max == contador){
            break;
        }
        contador++;
    }
    return linea;
}

string Mundo::generateSport(){
    ifstream archivo_nombre("/Users/mam12/Downloads/Avengers/Avengers/Deportes.txt");
    string linea;

    int contador = 0;
    int max = rand()%26;

    while(getline(archivo_nombre, linea)){
        if(max == contador){
            break;
        }
        contador++;
    }
    return linea;
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

void Mundo::generateCouple(Persona *p){
    if (p->estadoMarital != "Soltero" && !p->parejaAsignada){
        NodoPersona * nodo = listaPersonas->primerNodo;
        while(nodo != NULL){
            Persona * pConyuge = nodo->persona;
            if (pConyuge->grupoEtario == p->grupoEtario){
                if (pConyuge->genero != p->genero){
                    if (pConyuge->estadoMarital == p->estadoMarital && !pConyuge->parejaAsignada){
                        p->conyuge = pConyuge;
                        pConyuge->conyuge = p;
                        p->parejaAsignada = true;
                        pConyuge->parejaAsignada = true;
                        break;
                    }
                }
            }
            nodo = nodo->siguiente;
        }
        if (nodo == NULL){
            p->parejaAsignada = true;
            p->estadoMarital = "Soltero";
            p->hijosAsignados = true;
        }
    }
}

void Mundo::generateCountryVisits(Persona *p){
    int cantPaises;
    int n = rand()%100;
    if (n < 30){
        cantPaises = rand()%3;
    } else if (n < 55){
        cantPaises = rand()%9 + 2;
    } else if (n < 75){
        cantPaises = rand()%6 + 10;
    } else if (n < 90){
        cantPaises = rand()%10 + 16;
    } else{
        cantPaises = rand()%11 + 25;
    }

    Lista * l = new Lista();
    while (cantPaises != 0){
        string pais = generateCountry();
        if (pais != p->pais && !l->isInList(pais)){
            cantPaises--;
            l->insert(pais);
        }
    }
    p->paises = l;
}

Lista * Mundo::generateSports(Persona *p){
    int deportes = p->ejercicio;
    Lista * l = new Lista();
    while (deportes != 0){
        string deporte = generateSport();
        if (!l->isInList(deporte)){
            deportes--;
            l->insert(deporte);
        }
    }
    return l;
}

void Mundo::generateKids(Persona *p){
    if (!p->hijosAsignados){
        ListaPersonas * lista = new ListaPersonas();
        NodoPersona * nodo = listaPersonas->primerNodo;
        int cantHijos = rand()%5;
        while(cantHijos != 0 && nodo != NULL){
            Persona * pHijo = nodo->persona;
            if (pHijo->apellido == p->apellido || pHijo->apellido == p->conyuge->apellido){
                if (pHijo->pais == p->pais || pHijo->pais == p->conyuge->pais){
                    if (validateSon(p, pHijo)){
                        lista->insert(pHijo);
                        if (p->genero == "Hombre"){
                            pHijo->padre = p;
                            pHijo->madre = p->conyuge;
                        } else{
                            pHijo->padre = p->conyuge;
                            pHijo->madre = p;
                        }
                        cantHijos--;
                    }
                }
            }
            nodo = nodo->siguiente;
        }
        p->hijos = lista;
        p->conyuge->hijos = lista;
    }
}

void Mundo::createBirthdates(ListaPersonas * lista){
    NodoPersona * tmp = lista->primerNodo;
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
        p->generateAge(year, mes, dia);
        p->assignAgeGroup();
        tmp = tmp->siguiente;
    }
}


void Mundo::increaseSins(ListaPersonas * lista){
    NodoPersona * tmp = lista->primerNodo;
    while(tmp != NULL){
        tmp->persona->increaseSins();
        tmp = tmp->siguiente;
    }
}

void Mundo::increaseGoodActions(ListaPersonas * lista){
    NodoPersona * tmp = lista->primerNodo;
    while(tmp != NULL){
        tmp->persona->increaseGoodActions();
        tmp = tmp->siguiente;
    }
}

Persona * Mundo::findHuman(int id){
    /*NodoArbol * tmpA = arbol->raiz;
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
    }*/

    NodoPersona * nodo = listaPersonas->primerNodo;
    while (nodo != NULL){
        if (nodo->persona->id == id){
            return nodo->persona;
        }
        nodo = nodo->siguiente;
    }
    return NULL;

}

void Mundo::printHuman(int id){
    Persona * p = findHuman(id);
    if (p != NULL){
        p->printPerson();
    } else{
        cout << "ESA PERSONA NO EXISTE" << endl;
    }
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

        NodoPersona * amigo = p->amigos->primerNodo;
        while (amigo != NULL){
            ListaPersonas * amigosDeAmigo = amigo->persona->amigos;

            NodoPersona * amigoDeAmigo = amigosDeAmigo->primerNodo;
            while (amigoDeAmigo != NULL){
                lista->insert(amigoDeAmigo->persona);
                amigoDeAmigo = amigoDeAmigo->siguiente;
            }
            amigo = amigo->siguiente;
        }

        cout << "SE HIZO LA LISTA" << endl;
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
    cout << "XD" << endl;
}

string Mundo::generateMaritalState(Persona *p){
    int n = rand() % 100;
    if (n < 10){
        p->hijosAsignados = true;
        p->parejaAsignada = true;
        return "Soltero";
    } if (n < 90){
        return "Casado";
    } else{
        return "Divorciado";
    }
}

bool Mundo::validateSon(Persona *padre, Persona *hijo){
    if (padre->grupoEtario == "Joven"){
        if (hijo->grupoEtario == "Infantil" || hijo->grupoEtario == "Pre-escolar"){
            return true;
        }
    } else if (padre->grupoEtario == "Adulto Joven"){
        if (hijo->grupoEtario == "Infantil" || hijo->grupoEtario == "Pre-escolar" || hijo->grupoEtario == "Escolar" || hijo->grupoEtario == "Pubertad"){
            return true;
        }
    } else if(padre->grupoEtario == "Adulto Maduro"){
        if (hijo->grupoEtario == "Adolescencia" || hijo->grupoEtario == "Joven" || hijo->grupoEtario == "Adulto Joven"){
            return true;
        }
    } else if (padre->grupoEtario == "Adulto Mayor"){
        if (hijo->grupoEtario == "Adulto Joven" || hijo->grupoEtario == "Adulto Maduro"){
            return true;
        }
    }
    return false;
}

void Mundo::stats(){
    NodoPersona * nodo = listaPersonas->primerNodo;
    int vivos = 0;
    int muertos = 0;
    int salvados = 0;
    while (nodo != NULL){
        if (nodo->persona->vivo){
            vivos++;
            if(nodo->persona->vidaMuerte->size() != 0){
                salvados++;
            }
        } else{
            muertos++;
        }
        nodo = nodo->siguiente;
    }
    cout << "Personas Vivas: " << vivos << endl;
    cout << "Personas Muertas: " << muertos << endl;
    cout << "Personas salvadas: " << salvados << endl;
}




void Mundo::CorvusGlaive(){
    int n = 5 * listaPersonas->size() / 100;
    ListaPersonasRestringida * lista = new ListaPersonasRestringida(n);
    NodoPersona * nodo = listaPersonas->primerNodo;
    while (nodo != NULL){
        lista->insertSortMax(nodo->persona);
        nodo = nodo->siguiente;
    }

    nodo = lista->primerNodo;
    while(nodo != NULL){
        nodo->persona->CorvusGlaive();
        nodo = nodo->siguiente;
    }
    delete lista;
}

void Mundo::Midnight(){
    int n = 5 * listaPersonas->size() / 100;
    ListaPersonasRestringida * lista = new ListaPersonasRestringida(n);
    NodoPersona * nodo = listaPersonas->primerNodo;
    while (nodo != NULL){
        lista->insertSortMin(nodo->persona);
        nodo = nodo->siguiente;
    }

    nodo = lista->primerNodo;
    while(nodo != NULL){
        nodo->persona->Midnight();
        nodo = nodo->siguiente;
    }
    delete lista;
}


void Mundo::Ironman(){
    ListaPersonas * lista = arbol->toList();
    int p = rand()%21 + 40;
    for (int i = 0; i < lista->size(); i++){
        int n = rand()%100;
        if (n < p){
            lista->returnIndex(i)->persona->Ironman();
        }
    }
}

void Mundo::Thor(){
    int n = rand() % arbol->size() + 1;
    ListaPersonas * lista = arbol->levelToList(n);
    for (int i = 0; i < lista->size(); i++){
        Persona * p = lista->returnIndex(i)->persona;
        if (p->padre != NULL){
            ListaPersonas * padre = p->padre->amigos;
            for (int j = 0; j < padre->size(); j++){
                padre->returnIndex(j)->persona->Thor();
            }
        }
        if (p->madre != NULL){
            ListaPersonas * madre = p->madre->amigos;
            for (int j = 0; j < madre->size(); j++){
                madre->returnIndex(j)->persona->Thor();
            }
        }
        for (int j = 0; j < p->amigos->size(); j++){
            p->amigos->returnIndex(j)->persona->Thor();
        }
    }
}
