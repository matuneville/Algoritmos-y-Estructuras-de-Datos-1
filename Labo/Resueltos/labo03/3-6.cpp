#include <iostream>
using namespace std;

/*
 * void triplicaPorValor (int n){
    n *= 3;
}

 no funciona pues le estoy mandando una copia de la variable a la funcion,
 la funcion se ejecuta pero mi variable no es modificada, por lo que al
 devolver mi variable, es igual a la que oy ingresé

*/
void triplicaPorReferencia (int & n){
    n *= 3;
}


int main () {
    int x;

    cout<<"Ingrese el numero que sera triplicado: ";
    cin>> x;
    triplicaPorReferencia(x);
    cout<<x;
}