#include <iostream>
using namespace std;

int notasAlumnos (int nota) {
    cout << "Ingrese 13 para finalizar."<< endl;
    cout << "Ingrese la nota del alumno: ";
    cin >> nota;

    if (nota == 13)
        return nota;

    while (nota < 0 || nota > 10) {
        cout << "La nota debe estar entre 0 y 10. Ingrese nuevamente la nota: ";
        cin >> nota;
    }

    return nota;
}

int main() {
    int stop = 1;
    int i = 0 ;
    int notasTotal = 0;
    int nota = 0;

    while (stop != 13) {
        nota = notasAlumnos(nota);
        if (nota == 13)
            stop = nota;
        else {
            notasTotal += nota;
            i++;
        }
    }
    cout << "El promedio de notas es: "<< float(notasTotal)/float(i);
}
