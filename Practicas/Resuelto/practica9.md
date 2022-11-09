# Práctica 9
*No tenía ganas de hacer los programas en lapiz y papel porque algunos son larguitos jaja*
```C++
// llamo tipo mat ector<vector<int>>
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

```C++
```

```C++
```

```C++
```

```C++
```

```C++
```
