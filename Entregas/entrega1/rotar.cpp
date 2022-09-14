#include <iostream>
#include <vector>

using namespace std;

vector<int> rotar(vector<int> v, int k){
    // Dado un vector v y un entero k, rotar k posiciones los elementos de v.
    // [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
    vector<int> rotatedV;
    for (int i = k; i < v.size(); i++){
        rotatedV.push_back(v.at(i));
    }
    for (int i = 0; i < k; i++){
        rotatedV.push_back(v.at(i));
    }

    return rotatedV;
}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; //Longitud del vector a rotar
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    int k; // La cantidad que tengo que rotar la guardo en k
    cin >> k;
    
    // Hago la rotacion
    vector<int> res = rotar(v,k);
    i = 0;
    
    // Imprimo el vector resultado
    while (i < res.size()){
        cout << res[i] << " ";
        i++;
    }

    return 0;
}
