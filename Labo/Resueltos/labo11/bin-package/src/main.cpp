#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void insertionSort(vector< int > &arr){
    for(int j = 1; j < arr.size(); j++){
        int min = arr[j];
        int i = j-1;

        while(i >= 0 && arr[i] > min){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = min;
    }
}

void selectionSort(vector< int > &arr){
    for (int i = 0; i < arr.size(); ++i) {
        int posmin = i;
        for (int j = i+1; j < arr.size(); ++j) {
            if (arr[j] < arr[posmin])
                posmin = j;
        }
        int temp = arr[i];
        arr[i] = arr[posmin];
        arr[posmin] = temp;

    }
}

void countingSort(vector<int> &arr){
    int maxNum = arr[0], minNum = arr[0];
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] > maxNum)
            maxNum = arr[i];
        if(arr[i] < minNum)
            minNum = arr[i];
    }

    vector<int> countArr;
    vector<int> outputArr(arr.size(), 0);
    for (int i = minNum; i <= maxNum; ++i) {
        int countNum = 0;
        for (int j : arr) {
            if (i == j)
                countNum++;
        }
        countArr.push_back(countNum);
    }

    for (int i = 1; i < countArr.size(); ++i) {
        countArr[i] += countArr[i-1];
    }

    int i = 0, j = 0;
    while (i < arr.size() && j < countArr.size()){
        if(arr[i] == j){
            outputArr[countArr[j]-1] = arr[i];
            countArr[j]--;
            j = 0;
            i++;
        }
        else{
            j++;
        }
    }

    arr = outputArr;
}


void ordenar(vector<int> &items){
    vector<int> v = {1,3,0,5,0,13,0,0,19,1,2};
    countingSort(v);

    double t0 = clock();
    insertionSort(items);
    double t1 = clock();
    double timeSelection = (t1 - t0) / CLOCKS_PER_SEC;

/*
    t0 = clock();
    selectionSort(items);
    t1 = clock();
    double timeInsertion = (t1 - t0) / CLOCKS_PER_SEC;
*/

    cout<< "timeSelection: "<< timeSelection<< endl;
/*
    cout<< "timeInsertion: "<< timeInsertion<< endl;
*/
}


int bestFit(int W, vector<int> &items){
	multiset<int> restos;
	for(int i=0; i<(int)items.size(); ++i){
		restos.insert(W);
	}
	int res = 0;
	for(int i=0; i<(int)items.size(); ++i){
		multiset<int>::iterator it = restos.lower_bound(items[i]);
		int restoAct = *it;
		if(restoAct==W){
			res++;
		}
		restoAct -= items[i];
		restos.erase(it);
		restos.insert(restoAct);
	}
	return res;
}

int main(){

	int N, W, aux;

	//Se levantan los items y la capacidad del contenedor
	cout << "Se levantan los items y la capacidad del contenedor";
	ifstream bpp("BPP.in");
	bpp >> N >> W;
	vector<int> items;
	for(int i=0; i<N; ++i){
		bpp >> aux;
		items.push_back(aux);
	}
	bpp.close();
	//Se corre best-fit
	int cant1 = bestFit(W, items);
	cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

	//Se ordenan los items
	ordenar(items);
	//Se corre best-fit-decreasing
	int cant2 = bestFit(W, items);
	cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

	return 0;
}
