#include "generador.h"
#include "vectores.h"

using namespace std;

int main() {
    holaModuloVectores(); // función definida en vectores.cpp
    // Aca corro cada funcion para probar si anda piola
    mostrarVector(factoresPrimos(125));
    return 0;
}
