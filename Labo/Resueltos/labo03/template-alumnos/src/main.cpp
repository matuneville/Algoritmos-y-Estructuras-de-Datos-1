#include "generador.h"
#include "vectores.h"

using namespace std;

int main() {
    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    holaModuloVectores(); // función definida en vectores.cpp

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2 = rotar(vec1, 4);
    mostrarVector(vec2);

    return 0;
}
