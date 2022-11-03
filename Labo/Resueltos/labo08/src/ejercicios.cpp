#include "ejercicios.h"
#include <string>
#include <vector>

/* Para compilar */ 

using namespace std;

// *************************----- Ejercicio 1 -----*************************
vector<string> split(string s, char delim){
	vector<string> v;
    string palabra;
    s += delim;     // para leer bien la ultima palabra
    for (char index : s) {
        if (index != delim)
            palabra += index;
        else {
            if (not palabra.empty()) {      // sino va a pushear elemento vacio
                v.push_back(palabra);
                palabra = "";
            }
        }
    }
	return v;
}

// *************************----- Ejercicio 2 -----*************************
string darVueltaPalabra(string s){
	string res;
    vector<string> separoFrase;
    separoFrase = split(s, ' ');
    for (int i = separoFrase.size()-1; i >= 0; i--){
        res += separoFrase[i];
        if (i != 0)
            res += ' ';
    }
	return res;
}

// *************************----- Ejercicio 3 -----*************************
bool subsecuencia(string s1, string s2) {
	int cont = 0;
    int j = 0;
    for (int i = 0; i < s1.length(); i++){
        while (j < s2.length() && not s2.empty()) {
            if (s2[j] == s1[i]) {
                cont++;
                j++;
                break;
            }
            j++;
        }
    }
	return (cont == s1.length() || s1.empty());
}

// *************************----- Ejercicio 4 -----*************************
bool esAnagrama(string A, string B);
int apariciones(char c, string A);
bool esPalabraLeida(vector<int> vec, int i);

vector<vector<string> > agruparAnagramas(vector<string> v){
    vector<vector<string>> res;
    vector<int> palabrasLeidas;     // guardo indices de palabras guardadas para no repetir anagramas
    for (int i = 0; i < v.size(); ++i) {
        vector<string> anagramas;
        for (int j = i; j < v.size(); ++j) {
            if (esAnagrama(v[i], v[j]) && not esPalabraLeida(palabrasLeidas, j)) {
                anagramas.push_back(v[j]);
                palabrasLeidas.push_back(j);
            }
        }
        if (not anagramas.empty())
            res.push_back(anagramas);
    }
    return res;
}

bool esAnagrama(string A, string B){
    int contador = 0;
    for (int i = 0; i < A.length(); ++i) {
        if (apariciones(A[i], A) == apariciones(A[i], B))
            contador++;
    }
    return (contador == A.length() && A.length() == B.length());
}

int apariciones(char c, string A){
    int contador = 0;
    for (int i = 0; i < A.length(); ++i) {
        if (A[i] == c)
            contador++;
    }
    return contador;
}

bool esPalabraLeida(vector<int> vec, int i){
    for (int j = 0; j < vec.size(); ++j) {
        if (vec[j] == i)
            return true;
    }
    return false;
}


// *************************----- Ejercicio 5 -----*************************
bool esPalindromo(string s){
	string reversed;
    for (int i = s.length()-1 ; i >= 0; --i) {
        reversed += s[i];
    }
	return (reversed == s);
}

// *************************----- Ejercicio 6 -----*************************
bool tieneRepetidos(string s){
	bool distinto = false;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            if (s[j] == s[i] && i != j)
                distinto = true;
        }
    }
	return distinto;
}

// *************************----- Ejercicio 7 -----*************************
string rotar(string s, int j){
	string res;
    while (j - int (s.length()) >= 0){      // sin el int fallaba porque s.length() es unsigned
        j -= s.length();
    }
    for (int i = s.length() - j; i < s.length(); ++i) {
        res += s[i];
    }
    for (int i = 0; i < s.length() - j; ++i) {
        res += s[i];
    }
	return res;
}

// *************************----- Ejercicio 8 -----*************************
// no se puede usar subseq
string darVueltaK(string s, int k){
	string res;
	return res;
}

// *************************----- Ejercicio 10.1 -----*************************
string abueloLaino(string s){
    string res = "S";
    for (char i : s) {
        if (i == 'i')
            res = "N";
    }
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

int middleOut(string s, string t){

    return 0;
}
