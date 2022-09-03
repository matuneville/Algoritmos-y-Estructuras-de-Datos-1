#include <iostream>
using namespace std;

int notasAlumnos (int nota) {

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
    int alumnosAprobados = 0;
    int alumnosDesaprobados = 0;

    cout << "Ingrese 13 para finalizar."<< endl;

    while (stop != 13) {
        nota = notasAlumnos(nota);
        if (nota == 13)
            stop = nota;
        else {
            if (nota >= 0 && nota <= 6)
                alumnosDesaprobados++;
            if (nota >= 7 && nota <= 10)
                alumnosAprobados++;

            notasTotal += nota;
            i++;
        }
    }

    if (i >= 6) {
        cout << "El promedio de notas es: " << float(notasTotal) / float(i) << endl;
        cout << "Hay " << alumnosAprobados << " alumnos aprobados" << endl;
        cout << "Hay " << alumnosDesaprobados << " alumnos desaprobados" << endl;
    }

    else
        cout << "La cantidad de alumnos debe ser mayor a 5. Vuelva a intentar.";
}
