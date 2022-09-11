#include <iostream>
using namespace std;

void swap (int &a, int &b){
    a = b + a;
    b = a - b;
    a = a - b;
}

int main () {
    int a, b;

    cout<<"Ingrese dos numeros a y b: ";
    cin>>a;
    cin>>b;
    swap (a, b);
    cout<< "ahora a es igual a "<< a<<endl;
    cout<< "ahora b es igual a "<< b;

}