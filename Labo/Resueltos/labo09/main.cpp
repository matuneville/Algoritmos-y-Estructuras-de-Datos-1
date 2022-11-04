#include "ejercicios.h"

using namespace std;

int main() {
/*
    // ****************** Ejercicio 1 y 2 ******************
    //vector ascendente
    ofstream saveTime;
    saveTime.open(
            "C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datosAsc.csv");

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
            "C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datosConRepetido.csv");

    saveTime2 << "n" << "\t" << "tiempo" << endl;

    for (int i = 0; i <= 10000; i += 500) {
        saveTime2 << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "iguales");
        hayDuplicados(v);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTime2 << netTimeInSecs << endl;
    }

    saveTime2.close();

    // ****************** Ejercicio 3 ******************
    // vector ascendente
    ofstream saveTime3;
    saveTime3.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datosAsc2.csv");

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
    saveTime4.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datosConRepetido2.csv");

    saveTime4 << "n" << "\t"<< "tiempo"<< endl;

    for (int i = 0; i <= 10000; i +=500) {
        saveTime4 << i << "\t";
        double time1 = clock();
        vector <int> v = construir_vector(i, "iguales");
        hayDuplicados2(v);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTime4 << netTimeInSecs<< endl;
    }

    saveTime4.close();

    // ****************** Ejercicio 4 ******************
    // cree las funciones nuevas con las complejidades pedidas en ejercicios.cpp

    ofstream saveTimeEj4_1;
    saveTimeEj4_1.open(
            "C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datos_O(1).csv");

    saveTimeEj4_1 << "n" << "\t" << "tiempo" << endl;

    for (int i = 100; i <= 100000; i *= 10) {
        saveTimeEj4_1 << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "asc");
        tieneElementoEnPrimerosCinco(v, 3);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTimeEj4_1 << netTimeInSecs << endl;
    }

    saveTimeEj4_1.close();

    ofstream saveTimeEj4_2;
    saveTimeEj4_2.open(
            "C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datos_O(n).csv");

    saveTimeEj4_2 << "n" << "\t" << "tiempo" << endl;

    for (int i = 100; i <= 100000; i *= 10) {
        saveTimeEj4_2 << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "asc");
        multiplicoTodosPorN(v, 3);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTimeEj4_2 << netTimeInSecs << endl;
    }

    saveTimeEj4_2.close();


    ofstream saveTimeEj4_3;
    saveTimeEj4_3.open(
            "C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datos_O(n^3).csv");

    saveTimeEj4_3 << "n" << "\t" << "tiempo" << endl;

    for (int i = 100; i <= 100000; i *= 10) {
        saveTimeEj4_3 << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "asc");
        vector<vector<int>> m;
        for (int j = 0; j < v.size(); ++j) {
            m.push_back(v);
        }
        sumoN(m, 3);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTimeEj4_3 << netTimeInSecs << endl;
    }

    saveTimeEj4_3.close();

    // lo corte en el segundo porque ya habian pasado 2 minutos y seguia corriendo
    // claramente a partir de 10000 ya era una matriz inmensa y el tiempo de
    // ejecucion sería muy largo

    ofstream saveTimeEj4_4;
    saveTimeEj4_4.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datos_O(nlog(n)).csv");

    saveTimeEj4_4 << "n" << "\t" << "tiempo" << endl;

    for (int i = 100; i <= 100000; i *= 10) {
        saveTimeEj4_4 << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "asc");
        binariaNVeces(v, 100001);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTimeEj4_4 << netTimeInSecs << endl;
    }

    saveTimeEj4_4.close();

    */

    // O(1), O(n) y O(n log n) no tardaron nada, pero la cubica una barbaridad jaja

    // ****************** Ejercicio 6 ******************

    ofstream saveTimeEj6;
    saveTimeEj6.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo09/archivos/datosAlgunSubconj.csv");

    saveTimeEj6 << "n" << "\t" << "tiempo" << endl;

    for (int i = 0; i <= 50; i+= 10) {
        saveTimeEj6 << i << "\t";
        double time1 = clock();
        vector<int> v = construir_vector(i, "asc");
        algunSubconjSuma(v, 131);
        double time2 = clock();

        double netTimeInSecs = double(time2 - time1) / CLOCKS_PER_SEC;
        saveTimeEj6 << netTimeInSecs << endl;
    }

    saveTimeEj6.close();

    // no entiendo bien como funcionaba esta funcion pero
    // cuanto mayor sea la suma pedida, mas tardaba,
    // por eso lo hice cortito y con suma pequeña
    // tiene pinta de que era O(n^2) viendo el grafico

    return 0;
}