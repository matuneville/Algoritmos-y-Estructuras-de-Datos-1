#include <iostream>
using namespace std;

void divisionEntera (int dividendo, int divisor, int &cociente, int &resto){

    if (dividendo < 0 || divisor <= 0)
        cout<< "No cumple las precondiciones.";

    else {
        cociente = dividendo / divisor;
        resto = dividendo % divisor;
    }
}

int main () {
    int dividendo, divisor, cociente, resto;
    cout<< "Ingrese un dividendo y un divisor:"<< endl;
    cin>> dividendo;
    cin>> divisor;
    divisionEntera(dividendo, divisor, cociente, resto);
    cout<< "El cociente es "<< cociente << " y el resto es "<< resto;

}