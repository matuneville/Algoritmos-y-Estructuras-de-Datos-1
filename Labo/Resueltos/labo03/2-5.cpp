#include <iostream>
using namespace std;

double calculoCirculo (double radio, double& diametro, double& circunferencia, double& area){
    double pi = 3.14159;
    diametro = 2 * radio;
    circunferencia = pi * diametro;
    area = pi * radio * radio;
}

int main () {
    double radio, diametro, circunferencia, area;
    cout<< "Ingrese el radio de un circulo: ";
    cin>> radio;
    calculoCirculo(radio, diametro, circunferencia, area);
    cout<< "Diametro: "<< diametro<<endl;
    cout<< "Circunferencia: "<< circunferencia<<endl;
    cout<< "Area: "<< area<<endl;

}