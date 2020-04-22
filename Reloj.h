#include <iostream>

using namespace std;

class Reloj {
public:

    Reloj();
    //constructor default

    Reloj(int x, y);
    //constructor con parametros

    void setHora(int h) { hora = ((h >= 0 && h <= 24) ? h : 0); };
    void setMin(int m) {
        min = ((m >= 0 && m <= 59) ? m : 0););
        int getHora() { return hora; };
        int getMin() { return min; };
        //metodos de acceso set y get

        void muestra();
        //metodo muestra
private:

    int hora, min;

    };

    Reloj::Reloj() {
        hora = 0;
        min = 0;
    }

    Reloj::Reloj(x, y) {
        hora = x;
        min = y;
    }

    void Reloj::muestra() {
        cout << getHora() << ":" << getMin() << endl;
    }

  return 0;
}