#include <iostream>
using namespace std;

int sumaDivisoresHasta (int n) {
    int r = 0 ;
    for (int i=1 ; i <= n ; i++){
        if (n % i == 0)
            r+= i ;
    }
    return r ;
}

int main () {
    int n;
    cin>> n ;
    cout<< sumaDivisoresHasta(n) ;
}