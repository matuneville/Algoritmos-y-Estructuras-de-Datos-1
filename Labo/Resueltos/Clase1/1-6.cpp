#include <iostream>
using namespace std;

int sumaImparesHasta (int n) {
    int r = 0 ;
    for (int i=1 ; i < n ; i++){
        if (i % 2 != 0)
            r+= i ;
    }
    return r ;
}

int main () {
    int n;
    cin>> n ;
    cout<< sumaImparesHasta(n) ;
}