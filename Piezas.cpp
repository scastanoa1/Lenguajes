#include "Habitacion.h"
#include "Piezas.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
//constructor
Piezas::Piezas() {
    head = nullptr;
    previous = nullptr;
    n=0;
}
void Piezas:: visualise(){
    Habitacion *travel;
    travel = head;
    while(travel != nullptr){
        cout<< travel->getNombre() <<" your room is the number "<< travel->getNumHab() <<endl;
        cout<< "Also you are between "<< travel->getAntes() <<" and "<< travel->getSigue()<<endl;
        travel = travel->getSigue();
    }
    delete travel;
}
void Piezas :: createList(){
    string name;
    string numbers;
    int number;
    ifstream book;
    previous = new Habitacion("null",0, nullptr);
    book.open(R"(C:\Proyecto_Lenguajes\Hotel\hotel.txt)",ios::in);
    if(book.fail()){
        cout<<"Error al encontrar el archivo"<<endl;
        exit(1);
    }
    while(!book.eof()){
        getline(book,name);
        getline(book,numbers);
        number = stoi(numbers);//stoi converts the string numbers into its integer version
        head = new Habitacion(name,number,head);
        n++;
        previous->setAntes(head);
        previous = head;
    }
    book.close();
    //delete temporal;
}
void Piezas::add(string name, int number){
    while(checkActual(number)) {
        if (checkBefore(number) && checkAfter(number)) {
            cout<< "Habitacion ya ocupada trate una nueva " << endl;
            cin >> number;
        }
        else if (checkAfter(number) && !checkBefore(number)){
            cout<<"Te ofrecemos la habitacion anterior, "<<number-1<<", porque la siguiente ya esta ocupada"<<endl;
            number-=1;
        }
        else if(!checkAfter(number) && checkBefore(number)){
            cout<<"Te ofrecemos la habitacion siguiente, "<<number+1<<", porque la anterior ya esta ocupada"<<endl;
            number+=1;
        }
    }
    head = new Habitacion(name, number, head);
    previous->setAntes(head);
    previous = head;
    n++;
    printlist();
}

void Piezas::printlist(){
    Habitacion *recorrer;
    recorrer = searchFirst();
    ofstream write;
    write.open(R"(C:\Proyecto_Lenguajes\Hotel\hotel.txt)",ios::out);
    while(recorrer->getAntes() != nullptr){
        write<<recorrer->getNombre()<<endl;
        write<<recorrer->getNumHab()<<endl;
        recorrer = recorrer->getAntes();
    }
    write<< recorrer->getNombre()<<endl;
    write<<recorrer->getNumHab();
    write.close();
}
Habitacion* Piezas::searchFirst() {
    Habitacion *first;
    first = head;
    while(first != nullptr && first->getSigue() != nullptr) {
        first = first->getSigue();
    }
    return first;
}
void Piezas::printAlf() {
    vector<string> arrNombre;
    Habitacion *travel;
    travel = head;
    string actual;
    while(travel != nullptr){
        arrNombre.insert(arrNombre.begin(), travel->getNombre());
        travel = travel ->getSigue();
    }
    for(int i=0;i<arrNombre.size();i++){
        for(int j=i+1;j<arrNombre.size();j++){
            if(arrNombre[i]>arrNombre[j]){
                actual = arrNombre[j];
                arrNombre[j] = arrNombre[i];
                arrNombre[i] = actual;
            }
        }
    }
    for(int i = 0; i < arrNombre.size(); i++){
        cout << arrNombre[i] << endl;
    }
    delete travel;
}
void Piezas::printLlegada() {
    Habitacion *recorrer;
    recorrer = searchFirst();
    while(recorrer != nullptr){
        cout<<recorrer->getNombre()<<endl;
        cout<<recorrer->getNumHab()<<endl;
        recorrer = recorrer->getAntes();
    }
}
void Piezas::search(int porHabitacion) {
    Habitacion *travel;
    travel = head;
    bool found = false;
    while(travel != nullptr){
        if(travel -> getNumHab() == porHabitacion ){
            found = true;
            break;
        }
        else{
            travel = travel-> getSigue();
        }
    }
    if(!found){
        cout<< "No se encontro ningun huesped en la habitacion "<<porHabitacion <<endl;

    }else{
        cout<<"En la habitacion " << porHabitacion<< " se encontro el huesped "<<travel->getNombre()<<endl;
    }
}

void Piezas::search(string porNombre) {
    Habitacion *travel;
    travel = head;
    bool found = false;
    while(travel != nullptr){
        if(travel -> getNombre() == porNombre ){
            found = true;
            break;
        }
        else {
            travel = travel->getSigue();
        }
    }
    if(!found){
        cout<<"No se encontro el huesped "<< porNombre<<endl;
    }else{
        cout<<"Se encontro al huesped "<<travel->getNombre()<<" en la habitacion "<<travel->getNumHab()<<endl;
    }
}
bool Piezas::checkAfter(int actual){
    Habitacion *travel;
    travel = head;
    while(travel != nullptr) {
        if (travel->getNumHab() == actual+1) {
            return true;
        } else {
            travel = travel->getSigue();
        }
    }
    return false;
}bool Piezas::checkActual(int actual) {
        Habitacion *travel;
        travel = head;
        while(travel != nullptr) {
            if (travel->getNumHab() == actual) {
                return true;
            } else {
                travel = travel->getSigue();
            }
        }
        return false;
    }
bool Piezas::checkBefore(int actual) {
    Habitacion *travel;
    travel = head;
    while(travel != nullptr) {
        if (travel->getNumHab() == actual-1) {
            return true;
        } else {
            travel = travel->getSigue();
        }
    }
    return false;
}
void Piezas::lookNeighbors(int consult) {
    Habitacion *travel;
    Habitacion *siguiente;
    Habitacion *anterior;
    travel = head;
    int next = consult+1;
    int before = consult-1;
    while(travel != nullptr){
        if(travel-> getNumHab() == next){
            siguiente = travel;
        }
        else if(travel-> getNumHab() == before) {
            anterior = travel;
        }
        travel = travel->getSigue();

    }
    bool f1= checkAfter(consult);
    bool f2 = checkBefore(consult);
    if(f1 && f2){
        cout<< "Se encontro un vecino en la habitacion siguiente "<<" se hace llamar "<<siguiente->getNombre()<<endl;
        cout<< "Se encontro un vecino en la habitacion anterior "<<" se hace llamar "<<anterior->getNombre()<<endl;

    }
    else if(f1){
        cout<< "Se encontro un vecino en la habitacion siguiente "<<" se hace llamar "<<siguiente->getNombre()<<endl;
    }
    else if (f2){
        cout<< "Se encontro un vecino en la habitacion anterior "<<" se hace llamar "<<anterior->getNombre()<<endl;
    }
    else{cout<<"No tienes vecinos ni delante ni detras "<<endl;
    }
}
void Piezas::crearMenu() {
int eleccion=0;
int valor1;
int numHab;
string nombre;
Piezas *l = new Piezas();
    l->createList();
    cout<<"\nBienvenido al hotel"<<endl;
    cout<<"1. Agregar un huesped \n2. Buscar un huesped por habitacion \n3. Buscar un huesped por nombre"<<endl;
    cout<<"4. Mostrar alfabeticamente \n5. Mostrar en orden de llegada \n6. Buscar vecino \n7. Salir" <<endl;
    while (eleccion != 7){
        cout<<"\nQue deseas hacer?"<<endl;
        cin >> eleccion;
        if (eleccion == 1) {
            cout << "\nIngrese el nombre del huesped: ";
            cin >> nombre;
            cout << "\nIngrese el numero de habitacion: ";
            cin >> numHab;
            l->add(nombre, numHab);
            l->printlist();
            }
        else if (eleccion == 2) {
            cout << "\nIngrese la habitacion a buscar: ";
            cin >> valor1;
            l->search(valor1);
            }
        else if (eleccion == 3){
            cout << "\nIngrese el nombre a buscar: ";
            cin >> nombre;
            l->search(nombre);
        }
        else if (eleccion == 4) {
                l->printAlf();
            }
        else if (eleccion == 5) {
                l->printLlegada();
            }
        else if(eleccion == 6){
            cout << "\nIngrese la habitacion a buscar: ";
            cin >> valor1;
            l->lookNeighbors(valor1);
        }
        else if (eleccion == 7) {
                cout << "Gracias por usar el programa" << endl;
            }
        else {
                cout << "Opcion no valida" << endl;
            }

    }
}