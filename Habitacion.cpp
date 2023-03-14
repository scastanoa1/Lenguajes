#include "Habitacion.h"
#include <utility>
using namespace std;

//constructors
    Habitacion :: Habitacion(string ocupante, int numero, Habitacion *siguiente){
        nombre = ocupante;
        numHab = numero;
        sigue = siguiente;
        anterior = nullptr;
    }

//setters

void Habitacion::setAntes(Habitacion *antes) {
    anterior = antes;
}

//Getters
int Habitacion::getNumHab()  {
    return numHab;
}

Habitacion *Habitacion::getSigue() {
    return sigue;
}

string Habitacion::getNombre(){
    return nombre;
}

Habitacion *Habitacion::getAntes() {
    return anterior;
}

