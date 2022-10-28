#include "ejercicios.h"

//------------------------------ Ejercicio 1 ------------------------------
vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
	vector<vector<int> > res;
    for(int i = 0; i < u.size(); i++){
        vector<int> w;
        for(int j = 0; j < v.size(); j++) {
            w.push_back(u[i]*v[j]);
        }
        res.push_back(w);
    }
	return res;
}

//------------------------------ Ejercicio 2 ------------------------------
void trasponer(vector<vector<int> > &m) {
    vector<vector<int>> mTraspuesta;
	for(int i = 0; i < m[0].size(); i++){
        vector<int> v;
        for (int j = 0; j < m.size(); ++j) {
            v.push_back(m[j][i]);
        }
        mTraspuesta.push_back(v);
    }
    m = mTraspuesta;
}

//------------------------------ Ejercicio 3 ------------------------------
// fua me costo un huevo hacer este
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
    vector<vector<int> > res;
    for(int i = 0; i < m1.size(); i++){
        vector<int> linesRes;
        for(int j = 0; j < m2[i].size(); j++){
            vector<int> v;
            for(int k = 0; k < m1[i].size(); k++) {
                v.push_back(m1[i][k] * m2[k][j]);
            }
            linesRes.push_back(sumaVector(v));
        }
        res.push_back(linesRes);
    }
    return res;
}

int sumaVector (vector<int> v){
    int suma = 0;
    for (int i = 0; i < v.size(); ++i) {
        suma += v[i];
    }
    return suma;
}

//------------------------------ Ejercicio 4 ------------------------------
vector<vector<int> > promediar(vector<vector<int> > m){
	vector<vector<int> > res;
    for (int i = 0; i < m.size(); ++i) {
        vector<int> v;
        for (int j = 0; j < m[i].size(); ++j) {
            vector<int> vecinos = readVecinos(m, i, j);
            int promedioVecinos = sumaVector(vecinos) / (vecinos.size());
            v.push_back(promedioVecinos);
        }
        res.push_back(v);
    }
	return res;
}

// junto vecinos en vector para usar sumaVector y promediarlo
vector<int> readVecinos(vector<vector<int> > m, int fila, int columna){
    vector<int> vectorVecinos;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++) {
            if(chequeoRango(m, fila+i, columna+j)){
                vectorVecinos.push_back(m[fila + i][columna + j]);
            }
        }
    }
    return vectorVecinos;
}

bool chequeoRango(vector<vector<int>>m, int fila, int columna){
    if(fila >= 0 && fila < m.size() && columna >= 0 && columna < m[fila].size())
        return true;
    return false;
}

//------------------------------ Ejercicio 5 ------------------------------
int contarPicos(vector<vector<int> > m) {
    int contadorPicos = 0;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            vector<int> vecinos = readVecinos(m,i,j);
            if (esPico(vecinos,m[i][j]))
                contadorPicos++;
        }
    }
    return contadorPicos;
}

bool esPico (vector<int> v, int elemento){
    int maximo = v[0];

    //hago bubble sorting
    while(not estaOrdenado(v)) {
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1]) {
                int a = v[i];
                v[i] = v[i + 1];
                v[i + 1] = a;
            }
        }
    }
    //asumo que hay al menos 2 vecinos
    if (v[v.size()-1] == v[v.size()-2])
        return false;
    else if (v[v.size()-1] == elemento)
        return true;
    else
        return false;
}

bool estaOrdenado(vector<int> v){
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i+1])
            return false;
    }
    return true;
}

//------------------------------ Ejercicio 6 ------------------------------
bool esTriangular(vector<vector<int> > m){
	if (esTriangularInferior(m) || esTriangularSuperior(m))
        return true;
    return false;
}

bool esTriangularInferior(vector<vector<int>> m){
    for (int i = 1; i < m.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if(m[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool esTriangularSuperior(vector<vector<int>> m){
    trasponer(m);
    return esTriangularInferior(m);
}

//------------------------------ Ejercicio 7 ------------------------------
bool hayAmenaza(vector<vector<int> > m){
	if (amenazaHorizontal(m) || amenazaVertical(m) ||
    amenazaDiagonal1(m) || amenazaDiagonal2(m)) {
        return true;
    }
    return false;
}

bool amenazaHorizontal(vector<vector<int>> m){
    for (int i = 0; i < m.size(); ++i) {
        if(seRepiteEl1(m[i]))
            return true;
    }
    return false;
}

bool amenazaVertical(vector<vector<int>> m){
    trasponer(m);
    return amenazaHorizontal(m);
}

bool amenazaDiagonal1(vector<vector<int>> m){
    vector<vector<int>> diagonales;
    for (int i = m.size()-1; i >= 0; --i) {
        vector<int> v;
        for (int n = 0; i+n < m.size() && n < m[i].size(); n++) {
            v.push_back(m[i + n][n]);
        }
        diagonales.push_back(v);
    }

    trasponer(m);

    for (int i = m.size()-1; i >= 0; --i) {
        vector<int> v;
        for (int n = 0; i+n < m.size() && n < m[i].size(); n++) {
            v.push_back(m[i + n][n]);
        }
        diagonales.push_back(v);
    }

    return amenazaHorizontal(diagonales);
}

bool amenazaDiagonal2(vector<vector<int>> m){
    trasponer(m);
    return amenazaDiagonal1(m);
}

bool seRepiteEl1 (vector<int> v){
    int contador = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] == 1)
            contador++;
    }

    if (contador > 1)
        return true;
    return false;
}
//------------------------------ Ejercicio 8 ------------------------------
int diferenciaDiagonales(vector<vector<int> > m) {
    vector<int> v1, v2;
    for (int i = 0; i < m.size(); ++i){
        v1.push_back(m[i][i]);
    }
    int A = sumaVector(v1);

    for (int i = 0; i < m.size(); ++i){
        v2.push_back(m[i][m.size()-1 - i]);
    }
    int B = sumaVector(v2);

    if (A > B)
        return A-B;
    else
        return B-A;
}

//------------------------------ Ejercicio Adicional ------------------------------
bool estaGanadoTaTeTi (vector<vector<int>> m){
    if (ganadoHorizontal(m) || ganadoVertical(m) ||
        ganadoDiagonal1(m) || ganadoDiagonal2(m)) {
        return true;
    }
    return false;
}

bool ganadoHorizontal(vector<vector<int>> m){
    for (int i = 0; i < m.size(); ++i) {
        if(hay3Seguidos(m[i]))
            return true;
    }
    return false;
}

bool ganadoVertical(vector<vector<int>> m){
    trasponer(m);
    return ganadoHorizontal(m);
}

bool ganadoDiagonal1(vector<vector<int>> m){
    vector<vector<int>> diagonales;
    for (int i = m.size()-3; i >= 0; --i) {
        vector<int> v;
        for (int n = 0; i+n < m.size() && n < m[i].size(); n++) {
            v.push_back(m[i + n][n]);
        }
        diagonales.push_back(v);
    }

    trasponer(m);

    for (int i = m.size()-3; i >= 0; --i) {
        vector<int> v;
        for (int n = 0; i+n < m.size() && n < m[i].size(); n++) {
            v.push_back(m[i + n][n]);
        }
        diagonales.push_back(v);
    }

    return ganadoHorizontal(diagonales);
}

bool ganadoDiagonal2(vector<vector<int>> m){
    trasponer(m);
    return ganadoDiagonal1(m);
}

bool hay3Seguidos (vector<int> v){
    int cruzOCirculo = v[0];
    int contador = 1;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != cruzOCirculo){
            cruzOCirculo = v[i];
            contador = 1;
        }
        else
            contador++;
    }

    if (contador >= 3)
        return true;
    else
        return false;
}