#include "vectores.h"
#include <fstream>


// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El modulo vectores fue cargado correctamente" << endl;
}


//Ejercicio 1
bool divide(vector<int> v, int a){
    //Dados un vector v y un entero a, decide si a divide a todos los elementos de v.
    int i = 0;
    while (i < v.size()){
        if (v[i] % a != 0)
            return false;
        i++;
    }
    return true;
}

//Ejercicio 2
int mayor(vector<int> v){
    // Dado un vector v, devuelve el valor maximo encontrado.
    int mayor = v.at(0);
    int i = 0;
    while (i < v.size()) {
        if (v.at(i) > mayor) {
            mayor = v.at(i);
        }
        i++;
    }
    return mayor;
}

//Ejercicio 3
vector<int> reverso(vector<int> v){
	// Dado un vector v, devuelve el reverso.
    vector <int> reverseV;

    for (int i = v.size()-1 ; i >= 0 ; i--){
        reverseV.push_back(v.at(i));
    }

    return reverseV;

}

//Ejercicio 4
vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
    vector<int> rotatedV;
    for (int i = k; i < v.size(); i++){
        rotatedV.push_back(v.at(i));
    }
    for (int i = 0; i < k; i++){
        rotatedV.push_back(v.at(i));
    }

    return rotatedV;
}

//Ejercicio 5
bool estaOrdenado(vector<int> v){
    //Dado un vector v de enteros no repetidos, devuelve verdadero si
    // el mismo esta ordenado (ya sea creciente o decrecientemente).
    int i = 0;

    if (v.size() == 1 || v.empty())
        return true;

    if (v.at(0) >= v.at(1)){
        while (i < v.size()-1){
            if (v.at(i)<v.at(i+1))
                return false;
            else
                i++;
        }
        return true;
    }
    else{
        while (i < v.size()-1){
            if (v.at(i)>v.at(i+1))
                return false;
            else
                i++;
        }
        return true;
    }
}

//Ejercicio 6
vector<int> factoresPrimos(int n){
	//que dado un entero devuelve un vector con los factores primos del mismo
    vector<int> primeFactors;
    for (int i = 2; i < n; i++){
        if (esPrimo(i) && n % i == 0){
            primeFactors.push_back(i);
        }
    }
    return primeFactors;
}

bool esPrimo (int n){
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

//Ejercicio 7
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
    cout<<"["<<v.at(0);
    for (int i = 1; i < v.size(); i++){
        cout<< ", "<< v.at(i);
    }
    cout<<"]";
}

//Ejercicio 8

vector<int> leerVector(string fileName){
    vector<int> vec1;
    int a;
    ifstream leerArchivo; //variable con la que voy a operar para leer readFile(ej8).txt
    leerArchivo.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo03/template-alumnos/archivos/" + fileName, ios::in); //abro readFile(ej8).txt

    while (not leerArchivo.eof()){ //.eof devuelve TRUE si no hay mas elementos, por eso uso while not
        leerArchivo >> a; //toma cada entero hasta que haya un espacio
        vec1.push_back(a);
    }
    leerArchivo.close();
    return vec1;
}

//Ejercicio 9
void guardarVector(vector<int> vec, string nombreArchivo){
    ofstream saveVector;
    saveVector.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo03/template-alumnos/archivos/out/" + nombreArchivo);
    for (int i = 0; i < vec.size(); i++) {
        saveVector << vec.at(i)<< " ";
    }

    saveVector.close();
    cout<< "Archivo guardado correctamente";
}

//Ejercicio 10
int elementoMedio(vector<int>v){
    for (int i = 0; i < v.size(); i++){
        if (sumaAnteriores(v, i) > sumaPosteriores(v, i))
            return v.at(i);
    }
}

int sumaAnteriores(vector<int>v, int i){
    int n = 0;
    for (int j = 0; j <= i; j++){
        n += v.at(j);
    }
    return n;
}
int sumaPosteriores(vector<int>v, int i){
    int n = 0;
    for (int j = v.size()-1; j > i; j--){
        n += v.at(j);
    }
    return n;
}

//Ejercicio 11
void cantApariciones(string nombreArchivo){
    vector<int> vec1 = leerVector(nombreArchivo + ".in");

    vector<int> numerosContados;

    ofstream archivoOut;
    archivoOut.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo03/template-alumnos/archivos/out/" + nombreArchivo + ".txt");
    int i = 0;
    while (i < vec1.size()){
        if (not yaLeido(vec1.at(i), numerosContados)){
            int contador = 0;
            int j = 0;
            while (j < vec1.size()){
                if (vec1.at(i) == vec1.at(j)){
                    contador++;
                }
                j++;
            }
            archivoOut<< vec1.at(i)<< " "<< contador<< endl;
            numerosContados.push_back(vec1.at(i));
        }
        i++;
    }
    archivoOut.close();
}

bool yaLeido (int n, vector<int> numerosContados){
    int i = 0;
    while (i < numerosContados.size()){
        if (n == numerosContados.at(i))
            return true;
        i++;
    }
    return false;
}

//Ejercicio 12
int cantidadAparicionesDePalabra(string nombreArchivo, string palabra){
    ifstream archivoIn;
    archivoIn.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo03/template-alumnos/archivos/" + nombreArchivo + ".in", ios::in);
    int contador = 0;
    string x;
    vector<string> vecx;
    while (not archivoIn.eof()){
        archivoIn >> x;
        vecx.push_back(x);
    }
    for (int i = 0; i < vecx.size(); i++){
        if (vecx.at(i) == palabra)
            contador++;
    }

    archivoIn.close();
    return contador;
}

//Ejercicio 13
void promedio(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut){
    vector<int> vec1 = leerVector(nombreArchivoIn1 + ".in");
    vector<int> vec2 = leerVector(nombreArchivoIn2 + ".in");
    vector<float> vecAverage;

    for (int i = 0; i < vec1.size(); i++){
        float promedio = (vec1.at(i) + vec2.at(i)) * 0.5;
        vecAverage.push_back(promedio);
    }
    guardarVectorDouble(vecAverage, nombreArchivoOut);
}

void guardarVectorDouble(vector<float> vec, string nombreArchivo){
    ofstream saveVector;
    saveVector.open("C:/Users/nevil/Documents/GitHub/uba-algo1/Labo/Resueltos/labo03/template-alumnos/archivos/out/" + nombreArchivo);
    for (int i = 0; i < vec.size(); i++) {
        saveVector << vec.at(i)<< " ";
    }

    saveVector.close();
    cout<< "Archivo guardado correctamente";
}

//Ejercicio 14              CORREGIR !!!!
void ordenarSecuencias(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut){
    // Falta corregir que esta hecho para dos secuencias de mismo largo, y no añade el ultimo elemento :(
    vector<int> vec1 = leerVector(nombreArchivoIn1 + ".in");
    vector<int> vec2 = leerVector(nombreArchivoIn2 + ".in");
    vector<int> vecOrdenado;

    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size()){
        if (vec1.at(i) <= vec2.at(j)){
            vecOrdenado.push_back(vec1.at(i));
            i++;
        }
        else{
            vecOrdenado.push_back(vec2.at(j));
            j++;
        }
    }
    guardarVector(vecOrdenado, nombreArchivoOut);
}

//Ejercicio 15
vector<int> interseccion(){
    string archivo1, archivo2;
    cout<< "Ingrese el nombre de dos archivos con su extension:"<<endl;
    cin>> archivo1;
    cin>> archivo2;
    vector<int> vec1, vec2, vec3;
    vec1 = leerVector(archivo1);
    vec2 = leerVector(archivo2);
    int i = 0, j;
    while (i < vec1.size()){
        j = 0;
        while (j < vec2.size()) {
            if (vec1.at(i) == vec2.at(j)) {
                vec3.push_back(vec1.at(i));
                j++;
            }
            else
                j++;
        }
        i++;
    }
    return vec3;
}