#include <iostream>
#include "Reloj.h"

//using namespace std;

class Tratamiento {
public:    
    Tratamiento();
    //constructor default


    void setcveTreatment(string cveTreatment);
    void setnumTreatment(int numTreatment);
    void settreatmentRoom(int treatmentRoom);
    void sethour(Reloj hour);
    string getcveTreatment();
    int getnumTreatment();
    int gettreatmentRoom();
    Reloj gethour();
    //metodos de acceso set y get




    void muestra();
    //metodo muestra


private:
    string cve;
    //Clave de tratamiento 
    int numTreat;
    int room;
    Reloj h;
   


};

Tratamiento :: Tratamiento() {

}

void Tratamiento :: setcveTreatment(string cveTreatment){
      cve = cveTreatment;
}

void Tratamiento :: setnumTreatment(int numTreatment){
  //Se verifica que sea igual al número en el archivo

  numTreat = numTreatment;
}

void Tratamiento :: settreatmentRoom(int treatmentRoom){
  room = treatmentRoom;
}

void Tratamiento :: sethour(Reloj hour){
  h = hour;
}


string Tratamiento :: getcveTreatment(){
    return cve;
}

int Tratamiento :: getnumTreatment(){
    return numTreat;
}

int Tratamiento :: gettreatmentRoom(){
    return room;
}

Reloj Tratamiento :: gethour(){
    return h;
}


void Tratamiento :: muestra(){
  cout << cve << numTreat << room << h << endl;
}
