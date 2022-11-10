# Práctica 9
*No tenía ganas de hacer los programas en lapiz y papel porque algunos son larguitos jaja*
```C++
// llamo tipo mat: vector<vector<int>>
```
## Ejercicio 1
```C++
pair<int,int> coordinates(mat m, int x){
    pair<int,int> result;
    int row = 0, column = 0;
    for (row; row < m.size(); row++){
        for (column; column < m[row].size(); column++){
            if (m[row][column] == x){
                result = <row, column>;
                return result;
            }
        }
    }
    return {-1,-1};
}
```

## Ejercicio 3
```C++
int squareRootBinary(int n){
    int low = 1, high = n;
    while (low <= high){                // complejidad O(log n) por ser como binary search
        int mid = (low + high)/2;
        if (mid*mid == n)
            return mid;
        else if (mid*mid > n)
            high = mid-1;
        else
            low = mid+1;
    }
    return high;
}
```

## Ejercicio 4
a)
```C++
int summation(vector<int> v){
    int counter = 0;
    for (int i = 0; i < v.size(); i++){
        counter += v[i];
    }
    return counter;
}
```
b)
```C++
int summationBinary(vector<int> v){
    int low = 0, hight = v.size()-1;
    while (low <= high){
        int mid = (low + high)/2;
        if (v[mid] == 0) low = mid + 1;
        else high = mid - 1;
    }
    return v.size() - (mid+1);  // como estan los 0 de la izq y los 1 de la derecha
                              // los cuento directamente asi
}
```
c)
```C++
int summationBinary2(vector<int> v){
    int low = 0, hight = v.size()-1;
    while (low <= high){
        int mid = (low + high)/2;
        if (v[mid] == 15) low = mid + 1;
        else high = mid - 1;
    }
    int result = (mid+1)*15 + (v.size()-(mid+1))*22;
    return result; 
}
```

## Ejercicio 5
a)
```C++
int countAppearance(mat m, int x){
    int i = 0, j = m[i].size()-1;
    while (i < m.size() && j >= 0){ // O(n+m)
        if (m[i][j] < x)
            i++;        // paso a la otra fila
        else
            j--;        // paso a la otra columna
    }
    
    if (i<m.size() && j >= 0)
        return 1;       // pues no se repiten
    return 0;
}

```

b)
```C++
int countAppearance2(mat m, int x){
    int i = 0, j = m[i].size()-1, counter = 0;
    while (i < m.size() && j >= 0){     // O(n+m)
        if (m[i][j] == x)
            counter++;
        if (i+1 < m.size()-1 && m[i+1][0 == x){
            counter++;
            break;      // como mucho puede aparecer dos veces
        }
        
        if (m[i][j] < x)
            i++;        // paso a la otra fila
        else
            j--;        // paso a la otra columna
    }
    
    return counter;
}
```

c)
```C++
int countAppearance3(mat m, int x){
    int counter = 0;
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){  // O(n*m)
            if (m[i][j] == x)
                counter++;
        }
    }
    return counter;
}
```
## Ejercicio 6
a)
```C++
int appearances(vector<int> v, int e){
    int counter = 0;
    for (int i = 0; i < v.size(); i++){     // O(n)
        if (v[i] == e)
            counter++;
    }
    return counter;
}
```
b)
```C++
int differenceMaxMin(vector<int> v){
    int max = v[0], min = v[0];
    for(int i = 0; i < v.size(); i++){  // O(n)
        if (v[i] < min)
            min = v[i];
        if (v[i] > max)
            max = v[i];
    }
    
    if (max < 0) max *= (-1);
    if (min < 0) min *= (-1);
    
    return max - min;
}
```
c)
```C++
int appearances(vector<int> v, int x); // 0 ganas de codearla jaja pero es easy

int mostAppearedNum(vector<int> v){     // O(n^2) + O(n) = O(n^2)
    vector<int> eachOneAppearances;
    for(int i = 0; i < v.size(); i++){  // O(n)
        eachOneAppearances.pushback(appearances(v, v[i]));  // O(n)
    }
    // basicamente voy a buscar el numero mas grande en eachOneAppearances
    // y como son pusheados a medida que recorre v, sin excepcion,
    // entonces el indice del numero mas grande va a ser el indice
    // del numero que mas aparece en v. No dice nada acerca de si hay
    // varios que aparecen la misma cantidad de veces asi que devuelvo
    // el primero que encuentre.
    
    int maximumsIndex, max = v[0];
    for(int i = 0; i < v.size(); i++){  // O(n) pues |v| = |eachOneAppearances|
        if (v[i] > max){
            max = v[i];
            maximumsIndex = i;
        }
    }
    
    return v[maximumsIndex];
}
```
d) No entendi que pide  

e) Podría usarse un binary o jump search para obtener mejor complejidad.  

f) Sí (creo). Va a ahorrar pasos.

## Ejercicio 7
```C++
```
## Ejercicio 9
```C++
int diferenciaAbsoluta (int a, int b){
    if (a > b) return a-b;
    else return b-a;
}

vector<int> masCercanoK(vector<int> v, int k,  int x){
    bubbleSort(v);                          // hice el agoritmo para seq ordenadas ascendentmente
    vector<int> diferenciasAbs, result;     // entonces primero la ordeno
 
    for (int i = 0; i < v.size(); ++i) {        // O(n)
        diferenciasAbs.push_back(diferenciaAbsoluta(v[i], x));
    }

    while(result.size() != k){
        int indiceDelMinimo = 0, minimo = diferenciasAbs[0];
        for (int i = 0; i < diferenciasAbs.size(); ++i) {
            if (diferenciasAbs[i] < minimo && diferenciasAbs[i] > 0){
                minimo = diferenciasAbs[i];
                indiceDelMinimo = i;
            }
        }
        result.push_back(v[indiceDelMinimo]);
        diferenciasAbs[indiceDelMinimo] = 0;
    }
    bubbleSort(result);
    return result;
}
```
## Ejercicio 10
```C++
void doubleSelectionSort(vector<int> &v){
    while (not estaOrdenado(v)){    // O(n)
        for(int j = 0; v.size(); j++){
            int max = v[0], min = v[0];
            for(int i = j; i < v.size(); i++){  // O(n)
                if (v[i] < min)
                min = v[i];
                if (v[i] > max)
                max = v[i];
            }
            swap(v, min, v[j]);
            swap(v, max, v.size()-1 - j);
        }
    }
}
```
## Ejercicio 11
a) Este programa se va fijando de a dos elementos hasta llegar al final, y los intercambia si el primero es mayor que el segundo. Cuando llega al final vuelve al inicio y sigue fijandose si falta ordenarlos. Si es asi, los sigue swapeando.  

b) I = i <= 0 <= |a| && mismosElementos(a,A0) && estaOrdenado(subseq(a, 0, i)  

c) I = j <= 0 <= |a| && mismosElementos(a,A0) && (∀l : Z)(0 <= l < j → s[l] <= s[])  

d) O(n^2)  

## Ejercicio 12
```C++
void cocktailShakerSort(vector<int> a){
    int i = 0;
    int j;
    while (i < a.size()-1) {
        j = 0;
        while (j < a.size()-1) {
            if (a[j] > a[j+1]) {
                swap(a, j, j+1);
            }
            j++;
        }
        while (j >= 0) {
            if (a[j] < a[j-1]) {
                swap(a, j, j-1);
            }
            j--;
        }
    i++
    }
}                   // Complejidad O(n^2)

```
