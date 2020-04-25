#include <iostream>
#include <string.h>
#include "Doctor.h"


//Aqui se va a cargar el arreglo con la información del archivo grande

class CitaDental {

public:

    CitaDental();
    //constructor default
//    CitaDental(int numTreatment, int yearReceived, int timeOfTreatment, string specialtyArea, int doctorsQuantity, int idDoctor, string theTitle);
    //Constructor con parametros

    void setidDoctor(int id);
    void setnumTreatment(int nTreat);
    void settitle(string title);
    void setyear(int year);
    void settimeOfTreatment(int timeOfTreat);
    void setspecialtyArea(string specialty);
    void setdoctorsQuantity(int docQ);
    void setComparacionId(int idComp);
    //Doctors quantity solo puede recibir porque no es capaz de modificar la cantidad de actores directamente

    int getidDoctor();
    int getnumTreatment();
    string gettitle();
    int getyear();
    int gettimeOfTreatment();
    string getspecialtyArea();
    int getdoctorsQuantity();
    int getComparacionId();

    //metodos de acceso set y get

    bool checkDoctorsList(int);
    bool setdoctorsList(Doctor);
    void showDoctorsList();
    //Este entero corrependerá al subindice del arreglo de doctorsList que se quiere accesar
    //metodo para modificar lista de actores


    void printData();
    //metodo muestra
   
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
    int idCompared;
   

    int listIndex = 0;


};

CitaDental::CitaDental() {
    //falta poner valores default para los demás atributos.
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

bool CitaDental::checkDoctorsList(int id){
    for(int x=0; x<listIndex; x++){
    if(doctorsList[x].getidDoctor() == id){
      return true;
    }
  }
  return false;
}

bool CitaDental::setdoctorsList(Doctor doc) {

    if(!checkDoctorsList(doc.getidDoctor()) && listIndex<9 ){
      doctorsList[listIndex] = doc;
      listIndex++;
      return true;
    }
    return false;
}

void CitaDental :: setComparacionId(int idComp){
  idCompared = idComp;
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
int CitaDental :: getdoctorsQuantity(){
  return doctorsQuantity;
}
void CitaDental::printData() {
    cout << numTreatment << " - " << yearReceived << " - " << timeOfTreatment << " - " << specialtyArea << " - " << doctorsQuantity << " - ";
    for (int x = 0; x < listIndex; x++) {
        cout << doctorsList[x].getidDoctor() << " - " << doctorsList[x].getdoctorName() << " - ";
    }
    cout << theTitle << endl;
}
 void CitaDental :: showDoctorsList(){
   for(int i=0; i<listIndex; i++){
     cout<<doctorsList[i].getdoctorName()<<" ";
   }
 }
