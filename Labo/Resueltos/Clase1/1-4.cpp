#include <iostream>
using namespace std;

bool esPrimo (int p) {
    if (p==1)
        return false;
    else {
        for (int i = 2 ; i < p ; i++){
        if (p % i == 0)
            return false;
    }}
    return true;
}

int main() {
    int n ;
    cin >> n;
    cout<< esPrimo(n);
    return 0;
}