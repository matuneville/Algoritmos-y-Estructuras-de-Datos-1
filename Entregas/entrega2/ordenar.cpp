#include <vector>
#include <iostream>

using namespace std;


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

int main() {
    /* No hace falta modificar el main */
    
    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);
    
    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    
    return 0;
}
