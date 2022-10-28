#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v);
void trasponer(vector<vector<int> > &m);
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2);
vector<vector<int> > promediar(vector<vector<int> > m);
int contarPicos(vector<vector<int> > m);
bool esTriangular(vector<vector<int> > m);
bool hayAmenaza(vector<vector<int> > m);
int diferenciaDiagonales(vector<vector<int> > m);
bool estaGanadoTaTeTi (vector<vector<int>> m);

//auxiliares
int sumaVector (vector<int> v);
vector<int> readVecinos(vector<vector<int> > m, int fila, int columna);
bool esPico (vector<int> vecinos);
bool chequeoRango(vector<vector<int>>m, int fila, int columna);
bool estaOrdenado(vector<int> v);
bool esPico (vector<int> v, int elemento);
bool esTriangularSuperior(vector<vector<int>> m);
bool esTriangularInferior(vector<vector<int>> m);
bool amenazaHorizontal(vector<vector<int>> m);
bool amenazaVertical(vector<vector<int>> m);
bool amenazaDiagonal1(vector<vector<int>> m);
bool amenazaDiagonal2(vector<vector<int>> m);
bool seRepiteEl1 (vector<int> v);

bool ganadoHorizontal(vector<vector<int>> m);
bool ganadoVertical(vector<vector<int>> m);
bool ganadoDiagonal1(vector<vector<int>> m);
bool ganadoDiagonal2(vector<vector<int>> m);
bool hay3Seguidos (vector<int> v);