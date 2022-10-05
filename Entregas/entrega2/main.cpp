#include <iostream>
#include <vector>

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

int indiceMinSubsec(vector<int> v, int l, int r){
    if (l==r)
        return l;
    for (int i = l; i <= r; i++){
        if (throwMinimum(v)==v.at(i))
            return i;
    }
    return 0;
}

int main() {
    vector<int> v {1,4,2,3,1,2};
    cout<< indiceMinSubsec(v, 5, 5);
    return 0;
}
