#include "generador.h"
#include "vectores.h"

using namespace std;

int main() {
    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    holaModuloVectores(); // función definida en vectores.cpp

    //cout<<reverso({1,3,5,7});
    cout<< estaOrdenado({4,4,4,0,4,4,4});

    return 0;
}