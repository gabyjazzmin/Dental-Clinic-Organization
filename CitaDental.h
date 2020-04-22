#include <iostream>
#include <string.h>
#include "Doctor.h"

//Aqui se va a cargar el arreglo con la información del archivo grande

class CitaDental {

public:

    CitaDental();
    //constructor default
    CitaDental(int numTreatment, int yearReceived, int timeOfTreatment, string specialtyArea, int doctorsQuantity, int idDoctor, string theTitle);
    //Constructor default

    void setidDoctor(int id);
    void setnumTreatment(int nTreat);
    void settitle(string title);
    void setyear(int year);
    void settimeOfTreatment(int timeOfTreat);
    void setspecialtyArea(string specialty);
    void setdoctorsQuantity(int docQ);
    //Doctors quantity solo puede recibir porque no es capaz de modificar la cantidad de actores directamente

    int getidDoctor();
    int getnumTreatment();
    string gettitle();
    int getyear();
    int gettimeOfTreatment();
    string getspecialtyArea();

    //metodos de acceso set y get


    void setdoctorsList(Doctor);
    //Este entero corrependerá al subindice del arreglo de doctorsList que se quiere accesar
    //metodo para modificar lista de actores



    //metodo muestra
    void printData();
private:
    Doctor doctorsList[10];
    //Este es un arreglo de 10 elementos como máximo
    int doctorsQuantity;
    //Para almacenar la cantidad de doctores que hay
    int idDoctor;
    int numTreatment;
    string theTitle;
    int yearReceived;
    int timeOfTreatment;
    string specialtyArea;
   

    int listIndex = 0;


};

CitaDental::CitaDental() {
    //falta poner valores default para los demás atributos.
}

CitaDental::CitaDental(int numTreatment, int yearReceived, int timeOfTreatment, string specialtyArea, int doctorsQuantity, int idDoctor, string theTitle) {

}

void CitaDental::setidDoctor(int id) {
    idDoctor = id;
}

void CitaDental::setnumTreatment(int nTreat) {
    numTreatment = nTreat;
}

void CitaDental::settitle(string title) {
    theTitle = title;
}

void CitaDental::setyear(int year) {
    yearReceived = year;
}

void CitaDental::settimeOfTreatment(int timeOfTreat) {
    timeOfTreatment = timeOfTreat;
}

void CitaDental::setspecialtyArea(string specialty) {
    specialtyArea = specialty;
}

void CitaDental::setdoctorsQuantity(int docQ) {
    doctorsQuantity = docQ;
}

void CitaDental::setdoctorsList(Doctor doc) {
    doctorsList[listIndex] = doc;
    listIndex++;
}

int CitaDental::getidDoctor() {
    return idDoctor;
}

int CitaDental::getnumTreatment() {
    return numTreatment;
}

string CitaDental::gettitle() {
    return theTitle;
}

int CitaDental::getyear() {
    return yearReceived;
}

int CitaDental::gettimeOfTreatment() {
    return timeOfTreatment;
}

string CitaDental::getspecialtyArea() {
    return specialtyArea;
}

void CitaDental::printData() {
    cout << numTreatment << " - " << year << " - " << timeOfTreatment << " - " << specialtyArea << " - " << doctorsQuantity << " - ";
    for (int x = 0; x < listIndex; x++) {
        cout << doctorsList[x].getidDoctor() << " - " << doctorsList[x].getdoctorName() << " - ";
    }
    cout << title << endl;
}