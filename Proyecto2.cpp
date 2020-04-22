#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "CitaDental.h"


using namespace std;

int main() {
    //Lectura de archivo con nombres de doctores
    Doctor arreglo[20];
    ifstream archDoctors;
    archDoctors.open("ListaDoctores.txt");
    int cont = 0;
    string aux;
    while (!archDoctors.eof()) {
        int idDoctor;
        string nameDoctor;
        archDoctors >> idDoctor;
        getline(archDoctors, nameDoctor);
        arreglo[cont].setidDoctor(idDoctor);
        arreglo[cont].setdoctorName(nameDoctor);
        cont++;
    }
    for (int x = 0; x < 20; x++) {
        cout << arreglo[x].getdoctorName() << "   " << arreglo[x].getidDoctor() << endl;
    }

    //Lectura de archivo completo
    CitaDental arr[20];
    ifstream archEntrada;
    archEntrada.open("ArchivoCompleto.txt");
    int archCount = 0;
    while (!archEntrada.eof()) {
        int idTreatment, year, timeTreat, cantDoctors, idDoctor;
        string specialtyArea, treatment;

        archEntrada >> idTreatment >> year >> timeTreat >> specialtyArea >> cantDoctors;
        for (int i = 0; i < cantDoctors; i++) {
            archEntrada >> idDoctor;
            int index = 0;
            for (int x = 0; x < 20; x++) {
                if (idDoctor == arreglo[x].getidDoctor()) {
                    arr[archCount].setdoctorsList(arreglo[x]);
                    break;
                }
            }
        }
        getline(archEntrada, treatment);
        archCount++;
    }
    for (int x = 0; x < 20; x++) {
        arr[x].printData();
        cout << endl;
    }


    char cEntrada, cPregunta;
    cout << "Teclea 1 para iniciar el programa" << endl;
    cin >> cEntrada;
    cout << " " << endl;
    while (cEntrada == '1') {

        cout << "¡Hola! Bienvenido al menú del sistema de reservacion de este consultorio, te mostraremos las opciones, favor de teclear la que te convenga " << endl;
        cout << "[a] Consulta de todos los actores con sus datos" << endl;
        cout << "[b] Consultas de todas la peliculas mostrando título, año, duración, género y lista de los nombres de los actores " << endl;
        cout << "[c] Consulta de todas las funciones disponibles, mostrando clave de la función, nombre de la pelicula, numero de la sala y hora en la que se presenta " << endl;
        cout << "[d] Consulta de tratamientos por hora predeterminada " << endl;
        //Aqui mostramos el titulo de la pelicula y el numero de sala de todas los tratamientos que se presentan en esta hora que de el usuario
        cout << "[e] Consulta por clave de tratamiento " << endl;
        // Aqui el usuario introduce la clave del tratamiento
        //Se muestra al usuario  el numero de sala, el titulo del tratamiento, la hora a la que se presenta, la duracion, el area donde se hace el tratamiento y los nombres de los doctores en este procedimiento 
        cout << "[f] Consulta de los tratamientos en las que participa un doctor" << endl;
        // El usuario teclea el id del doctor
        // Se verifica que exista
        //Si existe mostrar el titulo del tratamiento en el que participa y el año de cada uno en el que esté presente
        cout << "[g] Terminar " << endl;
        cin >> cPregunta;



    }


    return 0;
}