#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    int n; // Cantidad de filas y columnas de la matriz
    cin >> n;
    int x;
    int filas = n, columnas = n;
    vector<vector<int> > m(filas, vector<int>(columnas, 0)); // En m leo la matriz
    
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            cin >> x;
            m[f][c] = x;
        }
    }

    bool res = esTriangular(m);
    cout << (res ? "true" : "false");    
    return 0;
}
