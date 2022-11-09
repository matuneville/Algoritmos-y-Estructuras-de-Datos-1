#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void ordenar(vector<int> &items){
    for(int j = 1; j < items.size(); j++){
        int min = items[j];
        int i = j-1;

        while(i >= 0 && items[i] > min){
            items[i+1] = items[i];
            i--;
        }
        items[i+1] = min;
    }

    for(int i = 0; i < items.size() / 2; i++){
        int temp = items[i];
        items[i] = items[items.size()-1-i];
        items[items.size()-1-i] = temp;
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

