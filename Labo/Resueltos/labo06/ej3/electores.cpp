#include <iostream>
#include "electores.h"

// no tenia ganas de hacer un programa que contara la cantidad
// de dias entre dos fechas dadas xD y no se me ocurrio otra
// forma de programar esto sin la cantidad de dias asi que la
// saque de google. Abrazo
#include "electoresAux.cpp"

using namespace std;

int validarVotante (int dd, int mm, int yyyy){
    Date nacimientoVotante = {dd, mm, yyyy};
    Date elecciones = {22, 10, 2022};

    // aca cuento la cantidad de dias con el algoritmo
    int diasDeVida = getDifference(nacimientoVotante, elecciones);

    if (fechaInvalida(yyyy, mm, dd))
        return ERROR;

    // si tiene menos de 16 años no vota
    if (diasDeVida < 365*16)
        return NO_VOTA;
    // si tiene entre 16 y 18 es opcional
    //aca no necesito aclarar que sea mayor a 16 porque ya paso el if anterior
    if (diasDeVida < 365*18)
        return OPCIONAL_MENOR;
    //aca lo mismo que antes
    if (diasDeVida < 70*365)
        return OBLIGATORIO;

    else
        return OPCIONAL_MAYOR;

}