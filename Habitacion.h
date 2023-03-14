#ifndef HOTEL_HABITACION_H
#define HOTEL_HABITACION_H
#include <string>
using namespace std;
class Habitacion{
protected:
    int numHab;
    Habitacion *sigue;
    string nombre;
    Habitacion *anterior;
public:
    //constructors
    Habitacion(string ocupante, int numero, Habitacion *siguiente);

    //getters
    int getNumHab();

    Habitacion *getSigue();

    string getNombre();

    Habitacion *getAntes() ;

//setters
    void setAntes(Habitacion *antes);
};
#endif //HOTEL_HABITACION_H
