#include "ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v){
	for (int i=1; i < v.size()-1; i++)
        if (v.at(i) > v.at(i-1) && v.at(i) > v.at(i+1))
            return true;
    return false;
}

// Ejercicio 2
int mcd(int m, int n) {
    for (int i = m; i > 1; i--) {
        if (m % i == 0 && n % i == 0)
            return i;
    }
    return 1;
}

// Ejercicio 3
int throwMinimum (vector<int> v){
    int i = 1;
    int minimo = v.at(0);
    while (i < v.size()){
        if (v.at(i) < minimo)
            minimo = v.at(i);
        i++;
    }
    return minimo;
}

int indiceMinSubsec(vector<int> v, int l, int r){
    for (int i = l; i <= r; i++){
        if (throwMinimum(v)==v.at(i))
            return i;
    }
	return 0;
}

// Ejercicio 4
void removeElem (vector<int> &v, int i){
    vector<int> removedV;
    for (int j = 0; j < v.size(); j++){
        if (j != i){
            removedV.push_back(v.at(j));
        }
    }
    v = removedV;
}

void ordenar1(vector<int>& v){
	vector<int> inOrderV;
    int i = 0;
    while (i < v.size()){
        if (throwMinimum(v)==v.at(i)){
            inOrderV.push_back(v.at(i));
            removeElem(v,i);
            i=0;
        }
        else
            i++;
    }
    v = inOrderV;
}

// Ejercicio 5
void ordenar2(vector<int>& v){
    ordenar1(v);
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
    int q = (n/d), r = (n%d);
	return make_tuple(q,r);
}
