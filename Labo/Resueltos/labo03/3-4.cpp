#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int binaryNum;
    int decimalNum = 0;
    int i = 0;
    cin>> binaryNum;

    while (binaryNum > 0){
        int digit = binaryNum % 10;
        if (digit == 1) {
            decimalNum += pow(2, i);
        }
        i++;
        binaryNum /= 10; // esto le quita la ultima cifra al numero
    }

    cout<< decimalNum;
}