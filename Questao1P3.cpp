#include <bits/stdc++.h>
using namespace std;

vector<int> vetor;
clock_t t1;


void imprimeVetores(int N){
	cout << endl;
	for(int i = 0; i<N; i++){
		if(i != N-1) cout << vetor[i] << ", ";
		else cout << vetor[i] << endl;
	}
	cout << endl;
}
void preparaVetor(vector<int> &v, int N){
	v.clear();
	for(int i = 0; i<N; i++){
		v.push_back(rand() %1000 + 1);
	}
}

void selectionSort(vector<int> &v, int n){
	int menor, i, j;
	for(i= 0; i < n-1; i++){
		menor= i;
		for(j= i+1; j< n; j++){
			if(v[j] < v[menor])
				menor= j;
		}
		swap(v[i],v[menor]);
	}
}

void merge(vector<int> &v, int pi, int m, int pf){
	int k= 0, i= pi, j= m+1, aux[pf+1];
	while(i <= m && j <= pf){
		if(v[i] > v[j]){
			aux[k]= v[j];
			j++;
		}else{
			aux[k]= v[i];
			i++;
		}
		k++;
	}
	for(;i <= m; i++){
		aux[k]= v[i];
		k++;
	}
	for(;j <= pf; j++){
		aux[k]= v[j];
		k++;
	}
	for(i= 0; i < k; i++)
		v[pi+i]= aux[i];

}

void mergeSort(vector<int> &v, int pi, int pf){
	int m;
	if(pi < pf){
		m= (pi+pf)/2;
		mergeSort(v, pi, m);
		mergeSort(v, m+1, pf);
		merge(v, pi, m, pf);
	}
}


int main(){
    preparaVetor(vetor, 100);
    cout << "Vetor desordenado de tamanho 100\n";
    imprimeVetores(100);
    t1= clock();
    selectionSort(vetor, 100);
    t1= clock() - t1;
    cout << "Vetor ordenado por selection sort\n";
    imprimeVetores(100);
    cout << "Tempo gasto para ordenar com o vetor de 100 selection: " << (float)t1/CLOCKS_PER_SEC << " segundos" << endl << endl;

    cout << "\n---------------------------------------------------------------------------------------------------------\n";

    preparaVetor(vetor, 100);
    cout << "Vetor desordenado de tamanho 100\n";
    imprimeVetores(100);
    t1= clock();
    mergeSort(vetor, 0, 99);
    t1= clock() - t1;
    cout << "Vetor ordenado por merge sort\n";
    imprimeVetores(100);
    cout << "Tempo gasto para ordenar o vetor de 100 com merge: " << (float)t1/CLOCKS_PER_SEC << " segundos" << endl << endl;

    cout << "\n---------------------------------------------------------------------------------------------------------\n";

    preparaVetor(vetor, 100000);
    t1= clock();
    selectionSort(vetor, 100000);
    t1= clock() - t1;
    cout << "Tempo gasto para ordenar com o vetor de 100000 selection: " << (float)t1/CLOCKS_PER_SEC << " segundos" << endl << endl;

    cout << "\n---------------------------------------------------------------------------------------------------------\n";

    preparaVetor(vetor, 100000);
    t1= clock();
    mergeSort(vetor, 0, 99999);
    t1= clock() - t1;
    cout << "Tempo gasto para ordenar com o vetor de 100000 merge: " << (float)t1/CLOCKS_PER_SEC << " segundos" << endl << endl;

    cout << "\n---------------------------------------------------------------------------------------------------------\n";

    cout << "A complexidade do algoritmo Selection Sort e: O(n^2)" << endl;
    cout << "A complexidade do algoritmo Merge Sort e: O(nLog(n))" << endl;
}
