#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino

int fibonacci(int n){
    int x=0,y=1;
    if (n==0)
        return 0;
    else {
        for (int i = 2; i < n; ++i) {
            int temp = x;
            x = y;
            y = y + temp;
        }
    }
    return x+y;
}

int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}