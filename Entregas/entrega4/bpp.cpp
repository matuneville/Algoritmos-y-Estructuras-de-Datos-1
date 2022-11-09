#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void ordenar(vector<int> &items){
    vector<int> repeticiones;
    int repe = 0;
    for(int i = 1; i <= 150; i++){
        for(int j = 0; j < items.size(); j++){
            if(items[j] == i) repe++;
        }
        repeticiones.push_back(repe);
        repe=0;
    }
    int k = items.size()-1;
    int p = 0;
    int n = 1;
    while(k >= 0){
        while(repeticiones[p] > 0 && p < repeticiones.size()){
            items[k] = n;
            repeticiones[p] -= 1;
            k--;
        }
        p++;
        n++;
    }
}


int bestFit(int W, vector<int> &items){
    multiset<int> restos;
    for(int i=0; i<(int)items.size(); ++i){
        restos.insert(W);
    }
    int res = 0;
    for(int i=0; i<(int)items.size(); ++i){
        multiset<int>::iterator it = restos.lower_bound(items[i]);
        int restoAct = *it;
        if(restoAct==W){
            res++;
        }
        restoAct -= items[i];
        restos.erase(it);
        restos.insert(restoAct);
    }
    return res;
}

int main(){
    int N, W, aux;

    //Se levantan los items y la capacidad del contenedor
    cin >> N >> W;
    vector<int> items;
    for(int i=0; i<N; ++i){
        cin >> aux;
        items.push_back(aux);
    }
    //Se corre best-fit
    int cant1 = bestFit(W, items);
    cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

    //Se ordenan los items
    ordenar(items);
    //Se corre best-fit-decreasing
    int cant2 = bestFit(W, items);
    cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

    return 0;
}

