#include <iostream>
using namespace std;

int fibonacci(int n){
    int x=0,y=1;
    for (int i = 2; i < n; ++i) {
        int temp = x;
        x = y;
        y = y + temp;
    }
    return x+y;
}

int main(){
    int n;
    cout << "Ingrese número:" << std::endl;
    cin >> n;
    cout << "Número de fibonacci nro " << n << ": " << fibonacci(n) << std::endl;
}