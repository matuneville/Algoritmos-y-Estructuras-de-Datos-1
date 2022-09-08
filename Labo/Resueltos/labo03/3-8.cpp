#include <iostream>
using namespace std;

void collatz (int n, int& cantPasos){

    cantPasos = 1;
    cout<< n<<endl;

    while (n != 1){
        if (n % 2 == 0){
            n /= 2;
            cout<< n<<endl;
            cantPasos++;
        }
        else {
            n = n*3 + 1;
            cout<< n<<endl;
            cantPasos++;
        }
    }

}

int main () {
    int num, pasos;
    cout<< "Ingrese un numero:"<<endl;
    cin>> num;
    cout<< "Sucesion de Collatz de "<< num<< endl;
    collatz(num, pasos);
    cout<< "Cantidad de pasos: "<< pasos;

}