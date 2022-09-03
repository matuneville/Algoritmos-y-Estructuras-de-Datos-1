#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int binaryNum;
    int decimalNum = 0;
    int potencia = 0;
    cin>> binaryNum;

    while (binaryNum > 0){
        int digit = binaryNum % 10;
        if (digit == 1) {
            decimalNum += pow(2, potencia);
        }
        potencia++;
        binaryNum /= 10; // esto le quita la ultima cifra al numero
    }

    cout<< decimalNum;
}