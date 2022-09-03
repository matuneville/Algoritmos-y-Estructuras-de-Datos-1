#include <iostream>
using namespace std;

int factorial(int n){
    int r = 1;
    for (int i = 1; i <= n; ++i) {
        r *= i;
    }
    return r;
}

int combinatoria(int n, int k) {
    n = (factorial(n) / (factorial(k) * factorial(n-k))) ;
    return n ;
}

int main () {
    int n, k ;
    cin>> n ;
    cin>> k ;
    cout<< combinatoria(n, k);
}