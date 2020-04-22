#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "CitaDental.h"


using namespace std;

int main() {
//Areglos
//----------------------------------------------
//Arreglo de Tratamiento 

//Arreglo y lectura de archivo con nombres de doctores
    Doctor arrDocList[20];
    ifstream archDoctors;
    archDoctors.open("ListaDoctores.txt");
    int cont=0;
    string aux;
    while (!archDoctors.eof()) {
        int idDoctor;
        string nameDoctor;
        archDoctors >> idDoctor;
        getline(archDoctors, nameDoctor);
        arrDocList[cont].setidDoctor(idDoctor);
        arrDocList[cont].setdoctorName(nameDoctor);
        cont++;
    }
    /*
    for(int x=0; x<20; x++){
      cout<<arrDocList[x].getdoctorName()<<"   "<<arrDocList[x].getidDoctor()<<endl;
    }
    */

//Arreglo y lectura de archivo completo
    CitaDental arrAllList[20];
        ifstream archEntrada;
        archEntrada.open("ArchivoCompleto.txt");
         int archCount = 0;
         while (!archEntrada.eof()) {
             int idTreatment, year, timeTreat, cantDoctors, idDoctor;
             string specialtyArea, treatment;

             archEntrada >> idTreatment >> year >> timeTreat >> specialtyArea >> cantDoctors;

             arrAllList[archCount].setnumTreatment(idTreatment); 
             
             arrAllList[archCount].setyear(year);

             arrAllList[archCount].settimeOfTreatment(timeTreat);

             arrAllList[archCount].setspecialtyArea(specialtyArea); 

             arrAllList[archCount].setdoctorsQuantity(cantDoctors);

             for (int i = 0; i < cantDoctors; i++) {
                 archEntrada >> idDoctor;
                    int index=0;
                     for(int x = 0; x < 20; x++){
                      if(idDoctor == arrDocList[x].getidDoctor()){
                        arrAllList[archCount].setdoctorsList(arrDocList[x]);
                        break;
                      }
                     }
                  }
                    getline(archEntrada, treatment);
                    archCount++;
                 }
                 /*
                 for(int x=0; x<20; x++){
                   arrAllList[x].printData();
                   cout<<endl;
                 }
                 */
  
    char cEntrada, cPregunta;
    cout << "Teclea 1 para iniciar el programa" << endl;
    cin >> cEntrada;
    cout << " " << endl;
    while(cEntrada == '1'){

cout << "¡Hola! Bienvenido al menú del sistema de reservacion de este consultorio, te mostraremos las opciones, favor de teclear la que te convenga " << endl;
cout << " " << endl;
cout << " " << endl;
cout << "[a] Consulta de todos los doctores con su id" << endl;
cout << "[b] Consultas de todas la peliculas mostrando título, año, duración, género y lista de los nombres de los actores " << endl;
cout << "[c] Consulta de todas las funciones disponibles, mostrando clave de la función, nombre de la pelicula, numero de la sala y hora en la que se presenta " << endl;
cout <<  "[d] Consulta de tratamientos por hora predeterminada " << endl;
//Aqui mostramos el titulo de la pelicula y el numero de sala de todas los tratamientos que se presentan en esta hora que de el usuario
cout << "[e] Consulta por clave de tratamiento " << endl;
// Aqui el usuario introduce la clave del tratamiento
//Se muestra al usuario  el numero de sala, el titulo del tratamiento, la hora a la que se presenta, la duracion, el area donde se hace el tratamiento y los nombres de los doctores en este procedimiento 
cout << "[f] Consulta de los tratamientos en las que participa un doctor" << endl;
// El usuario teclea el id del doctor
// Se verifica que exista
//Si existe mostrar el titulo del tratamiento en el que participa y el año de cada uno en el que esté presente
cout << "[g] Terminar " << endl;
cin >>cPregunta;

cout << " " << endl;
cout << " " << endl;

  switch(cPregunta){
    case 'a': 
    for(int x=0; x<20; x++){
      cout<<arrDocList[x].getdoctorName()<<"   "<<arrDocList[x].getidDoctor()<<endl;
    }

     cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

    case 'b':
    for(int x=0; x<20; x++){
                   arrAllList[x].printData();
                   cout<<endl;
                 }
     cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

    case 'c':
    cout << "hey" << endl;

     cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

    case 'd' :
    cout << "zup" << endl;
    
    cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

    case 'e':
    cout << "yey" << endl;

    cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

    case 'f':
    cout << "wuju" << endl;

    cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

    case 'g':
    cout << "Ha elegido terminar este proceso, cuidese y lavese los dientes" << endl;
    cEntrada = 0;

    break;

    default:
    cout << " " << endl;
    cout << "Haz dado una letra incorrecta, vuelve a introducir tu variable" << endl;
    cout << " " << endl;
    cEntrada = '1';
  }

    
  }


  return 0;
}
