#include "ejercicios.h"

using namespace std;

int main() {

    // ****************** Ejercicio 2 ******************
    //vector ascendente
    ofstream saveTime;
    saveTime.open(
            "C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/template-alumnos/archivos/datosAsc.csv");

    saveTime << "n" << "\t" << "tiempo" << endl;

    for (int i = 0; i <= 10000; i += 500) {
        saveTime << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "asc");
        hayDuplicados(v);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTime << netTimeInSecs << endl;
    }

    saveTime.close();

    //vector repetido
    ofstream saveTime2;
    saveTime2.open(
            "C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/template-alumnos/archivos/datosConRepetido.csv");

    saveTime2 << "n" << "\t" << "tiempo" << endl;

    for (int i = 0; i <= 10000; i += 500) {
        saveTime2 << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "asc");
        hayDuplicados(v);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTime2 << netTimeInSecs << endl;
    }

    saveTime2.close();

    // ****************** Ejercicio 3 ******************
    // vector ascendente
    ofstream saveTime3;
    saveTime3.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/template-alumnos/archivos/datosAsc2.csv");

    saveTime3 << "n" << "\t"<< "tiempo"<< endl;

    for (int i = 0; i <= 10000; i +=500) {
        saveTime3 << i << "\t";
        double time1 = clock();
        vector <int> v = construir_vector(i, "asc");
        hayDuplicados2(v);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTime3 << netTimeInSecs<< endl;
    }

    saveTime3.close();

    //vector repetido
    ofstream saveTime4;
    saveTime4.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/template-alumnos/archivos/datosConRepetido2.csv");

    saveTime4 << "n" << "\t"<< "tiempo"<< endl;

    for (int i = 0; i <= 10000; i +=500) {
        saveTime4 << i << "\t";
        double time1 = clock();
        vector <int> v = construir_vector(i, "asc");
        hayDuplicados2(v);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTime4 << netTimeInSecs<< endl;
    }

    saveTime4.close();

    return 0;
}