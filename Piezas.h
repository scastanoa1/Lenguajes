#ifndef HOTEL_PIEZAS_H
#define HOTEL_PIEZAS_H
#include "Habitacion.h"

class Piezas {
protected:
    Habitacion * head;
    Habitacion *previous;
    int n;
public:
    Piezas();
    void createList();
    void visualise();
    void add(string name, int number);
    bool checkAfter(int actual);
    bool checkBefore(int actual);
    bool checkActual(int actual);
    void search(string porNombre);
    void search(int porHabitacion);
    void printlist();
    void printLlegada();
    void printAlf();
    void crearMenu();
    void lookNeighbors(int consult);
    Habitacion* searchFirst();


};


#endif //HOTEL_PIEZAS_H
