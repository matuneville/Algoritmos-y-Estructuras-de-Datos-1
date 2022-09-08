#include <iostream>
using namespace std;

int notasAlumnos (int nota) {
    cout << "Ingrese la nota del alumno: ";
    cin >> nota;

    while (nota < 0 || nota > 10) {
        cout << "La nota debe estar entre 0 y 10. Ingrese nuevamente la nota: ";
        cin >> nota;
    }

    return nota;
}

int main() {
    int i = 1 ;
    int notasTotal = 0;
    int nota;

    while (i <= 10) {
        nota = notasAlumnos(nota);
        notasTotal += nota;
        i++;
    }
    cout << "El promedio de notas es: "<< float(notasTotal)/10;
}
