#include <iostream>

int fibo(int n){
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
    std::cout << "Ingrese número:" << std::endl;
    std::cin >> n;
    std::cout << "Número de fibonacci nro " << n << ": " << fibo(n) << std::endl;
}