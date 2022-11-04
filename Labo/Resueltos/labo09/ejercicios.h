#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

void mostrar_vector(vector<int>& v);
vector<int> construir_vector(int n, string disposicion);

bool hayDuplicados ( vector < int >& v );
bool hayDuplicados2 (vector<int>& v);

bool aux(vector<int>& vec, int i, int sum);
bool algunSubconjSuma(vector<int>& vec, int sum);

bool busqueda_binaria(vector<int> &s, int x);


void guardarTiempo(string nombreArchivo, int n, double tiempo);
bool tieneElementoEnPrimerosCinco(vector<int>& v, int n);
void multiplicoTodosPorN(vector<int>& v, int n);
void sumoN(vector<vector<int>>& v, int n);
void binariaNVeces(vector<int> &v, int x);