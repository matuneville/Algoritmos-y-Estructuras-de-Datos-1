#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El modulo vectores fue cargado correctamente" << endl;
}


//Ejercicio 1
bool divide(vector<int> v, int a){
    //Dados un vector v y un entero a, decide si a divide a todos los elementos de v.
    int i = 0;
    while (i < v.size()){
        if (v[i] % a != 0)
            return false;
        i++;
    }
    return true;
}

//Ejercicio 2
int mayor(vector<int> v){
    // Dado un vector v, devuelve el valor maximo encontrado.
    int mayor = v.at(0);
    int i = 0;
    while (i < v.size()) {
        if (v.at(i) > mayor) {
            mayor = v.at(i);
        }
        i++;
    }
    return mayor;
}

//Ejercicio 3
vector<int> reverso(vector<int> v){
	// Dado un vector v, devuelve el reverso.
    vector <int> reverseV;

    for (int i = v.size()-1 ; i >= 0 ; i--){
        reverseV.push_back(v.at(i));
    }

    return reverseV;

}

//Ejercicio 4
vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
}

//Ejercicio 5
bool estaOrdenado(vector<int> v){
    //Dado un vector v de enteros no repetidos, devuelve verdadero si
    // el mismo esta ordenado (ya sea creciente o decrecientemente).
    int i = 0;

    if (v.size() == 1 || v.empty())
        return true;

    if (v.at(0) >= v.at(1)){
        while (i < v.size()-1){
            if (v.at(i)<v.at(i+1))
                return false;
            else
                i++;
        }
        return true;
    }
    else{
        while (i < v.size()-1){
            if (v.at(i)>v.at(i+1))
                return false;
            else
                i++;
        }
        return true;
    }
}

//Ejercicio
vector<int> factoresPrimos(int n){
	//que dado un entero devuelve un vector con los factores primos del mismo
}

//Ejercicio
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
}
