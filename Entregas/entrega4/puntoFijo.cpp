#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int puntoFijo(vector<int> v){
    int jump = floor(sqrt(v.size()));
    int piso = v.size() - jump, techo = v.size()-1;

    for (int i = 0; i < v.size(); i += jump) {
        if (v[i] >= i){
            piso = i - jump;
            techo = i;
            break;
        }
    }
    if (piso < 0) piso = 0;
    for (int i = piso; i <= techo ; ++i) {
        if (v[i] == i) return i;
    }
    return -1;
}   // hecho con jumpsearch

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n;
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    // Calculo el punto fijo de v
    int res = puntoFijo(v);
    
    // Imprimo la salida
    cout << res;
    
    return 0;
}
