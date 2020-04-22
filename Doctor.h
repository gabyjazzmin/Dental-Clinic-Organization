#include <iostream>
#include <string.h>


using namespace std;

class Doctor {
public:

    Doctor();
    //constructor default

    Doctor(int idDoctor, string doctorName);
    //constructor con parametros

    void setidDoctor(int id);
    void setdoctorName(string name);
    int getidDoctor();
    string getdoctorName();
    //metodos de acceso set y get

    //metodo muestra

private:
    int idDoctor;
    string doctorName;

};

Doctor::Doctor() {
    idDoctor = 0;
    doctorName = "";

}

Doctor::Doctor(int idDoctor, string doctorName) {

}
//El atributo listaDoctores de la clase Cita Dental es un arreglo de 10 elementos

//El atributo cantidadDoctores de la clase Cita Dental es para almacenar la cantidad de actores que hay en el arrego de listaDoctores
void Doctor::setdoctorName(string name) {
    doctorName = name;
}

void Doctor::setidDoctor(int id) {
    idDoctor = id;
}

string Doctor::getdoctorName() {

    return doctorName;
}

int Doctor::getidDoctor() {

    return idDoctor;
}