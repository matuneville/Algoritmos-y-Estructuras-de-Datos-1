#include <iostream>
#include <vector>

using namespace std;

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
    
    // Evaluo si el vector v esta ordenado
    bool res = estaOrdenado(v);
    
    // Imprimo la salida
    cout << (res?"True":"False");
    
    return 0;
}
