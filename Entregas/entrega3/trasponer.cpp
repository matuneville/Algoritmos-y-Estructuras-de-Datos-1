#include <iostream>
#include <vector>

using namespace std;

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

    trasponer(m); 
    
    cout << filas << " " << columnas << endl;
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            cout << m[f][c] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

