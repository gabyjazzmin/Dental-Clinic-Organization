#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "CitaDental.h"
#include "Tratamiento.h"



using namespace std;

int main() {
//Areglos
//----------------------------------------------


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
                  arrAllList[archCount].settitle(treatment);
                    archCount++;
                 }
//Arreglo de Tratamiento 
Tratamiento arrAnswers[20];
string cveTreat;
int numCita, hour, min, room;
char respuesta;
bool check = false;
bool check2 = true;
int countTreatment=0;


   cout << "Hola, a continuación te pediremos datos para los tratamientos. Los datos por orden son: " << endl;
   cout << endl;

   cout << "Clave del Tratamiento " << endl;
   cout << "Cuarto de tratamiento" << endl;
   cout << "Numero de Cita Dental " << endl;
   cout << "Hora " << endl;
   cout << "Minutos " << endl;
   cout << " " << endl;

              do{
                
              cout << " " << endl;
                 
              cin >> cveTreat >> room >> numCita;
              do{
                cin >> hour >> min;
                if(((hour<0)||(hour>=24))||((min<0)||(min>=60))){
                  cout<< "hora y/o minuto invalido"<<endl;
                  cout << "Asegurate de poner correctamente la hora y minuto de nuevo " << endl;
                }
              } while(((hour<0)||(hour>=24))||((min<0)||(min>=60)));

              Reloj relojito(hour, min);

              arrAnswers[countTreatment].setcveTreatment(cveTreat);
              arrAnswers[countTreatment].settreatmentRoom(room);
         
     
      //Comparar si es igual al número de tratamiento
    for (int i =0;  i<20; i++){
      if(numCita == arrAllList[i].getnumTreatment()){
        arrAnswers[countTreatment].setnumTreatment(numCita);
        //cout << "El numero de citas si coincidio  " << endl; 
        check = true;
          } 
    }
    if(check){
      cout << "El numero de citas si coincidio y la hora es correcta " << endl; 
      check2=true;
    }
    else{
      cout << " El número de citas es incorrecto, vuelve a meter todos los datos. " << endl;
      check2= false;
    }
 
              arrAnswers[countTreatment].sethour(relojito);
              
              if(check2){
                cout << " " << endl;
                cout << "¿Deseas agregar una vez más datos del tratamiento? " << endl;
                cout << " " << endl;

              
                 
                 cout << "Teclea 1 para no agregar. En caso de que quieras agregar otro teclea cualquier tecla y escribe los datos indicados al incio" << endl;
              cin >> respuesta;
            countTreatment++;
              }
          }
             
             while((respuesta != '1') || (!check2) );
                 /*
                 for(int x=0; x<20; x++){
                   arrAllList[x].printData();
                   cout<<endl;
                 }
                 */
  
    char cEntrada, cPregunta;
    cout << "Teclea 1 para mostrar el menú" << endl;
    cin >> cEntrada;
    cout << " " << endl;
    while(cEntrada == '1'){

cout << "¡Hola! Bienvenido al menú del sistema de reservacion de este consultorio, te mostraremos las opciones, favor de teclear la que te convenga " << endl;
cout << " " << endl;
cout << " " << endl;
cout << "[a] Consulta de todos los doctores con su id" << endl;
cout << "[b] Consultas de todas los tratamientos mostrando título de tratamiento, año, duración, area de especialidad y lista de los nombres de los doctores" << endl;
cout << "[c] Consulta de todas las citas disponibles, mostrando clave del tratamiento, nombre del tratamiento, numero de la sala de operación y hora en la que se realiza  " << endl;
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

 cout << "Muestra de todas las funciones disponibles " << endl;
 cout << " " << endl;

        for(int x=0; x<countTreatment; x++){
          cout<<arrAnswers[x].getcveTreatment()<<" ";
          for(int i=0; i<archCount; i++){
            if(arrAnswers[x].getnumTreatment() == arrAllList[i].getnumTreatment()){
              cout<<arrAllList[i].gettitle()<<" ";
              break;
            }
          }
              cout<<arrAnswers[x].gettreatmentRoom()<<" "; 
              arrAnswers[x].gethour().muestra();
              cout<<endl;
        }
         cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

    case 'd' :

    int h,m;
  
    cout << "Ingresa hora y minuto " << endl;
    
    do{
    cin >> h >> m;
      if(((hour<0)||(hour>=24))||((min<0)||(min>=60))){
        cout << "Haz introducido una hora inexistente, vuelve a intentar." << endl;
      }
      }while(((hour<0)||(hour>=24))||((min<0)||(min>=60)));
    
    //Reloj relojitoCheca(h,m);
    for (int x = 0; x<archCount; x++ ){
        if((arrAnswers[x].gethour().getHora() == h) && (arrAnswers[x].gethour().getMin() == m) ){
          for(int i=0; i<archCount; i++){
            if(arrAnswers[x].getnumTreatment() == arrAllList[i].getnumTreatment()){
             // arrAllList[i].printData();
              cout<<arrAllList[i].gettitle()<<" ";
              cout<<arrAnswers[x].gettreatmentRoom()<<endl;
            }
          }
          

        }
    }
    cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;

      case 'e':{
    string cveUser;
    bool conf=false;
    int index=-1;
    cout << "Introduce la clave del tratamiento" << endl;
    
    while(!conf){
      cin >>cveUser;
      for(int x=0; x<archCount; x++){
      if(arrAnswers[x].getcveTreatment()==cveUser){
        index=x;
        conf=true;
      
      if(!conf){
        cout << "Introduce otra vez la clave ya que introdujiste una incorrecta " << endl; 
      }
      }
     }
    }
    cout<<arrAnswers[index].gettreatmentRoom()<<" ";
    for(int i=0; i<archCount; i++){
            if(arrAnswers[index].getnumTreatment() == arrAllList[i].getnumTreatment()){
              cout<<arrAllList[i].gettitle()<<" ";
              arrAnswers[index].gethour().muestra();
              cout<<" "<<arrAllList[i].gettimeOfTreatment()<<" "<<arrAllList[i].getspecialtyArea() << " "; 
              arrAllList[i].showDoctorsList();
              cout<<endl;
              break;
            }
          }
    
    cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;}

    case 'f':{
    int idVerify;
    int index=-1;
    bool conf=false;
    cout << "Teclea el id del doctor que buscas" << endl;

  
    while(!conf){
      cin >>idVerify;
      for(int x=0; x<cont; x++){
      if(arrDocList[x].getidDoctor()==idVerify){
        index=x;
        conf=true;
      }
     }
     if(!conf){
        cout << "Introduce otra vez la clave ya que introdujiste una incorrecta " << endl; 
      }
    }
    for(int x=0; x<archCount; x++){
        if(arrAllList[x].checkDoctorsList(idVerify)){
          cout<<arrAllList[x].gettitle()<<" "<<arrAllList[x].getyear()<<endl;
        }
    }
    cout << " " << endl;
        cout << "Si deseas volver a repetir este proceso, teclea 1"<< endl;
        cin >> cEntrada;
        cout << " " << endl;
    break;}

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
