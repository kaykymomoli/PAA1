#include <bits/stdc++.h>
using namespace std;

int partition(int *v, int p, int r){
	int x= v[p];
	int i= p-1;
	int j= r+1;
	while(i < j){
		do{
			j--;
		}while(v[j] > x);
		do{
			i++;
		}while(v[i] < x);
		if(i < j)
			swap(v[i], v[j]);
	}
	return j;
}

void quickSort(int *v, int p, int r){
	if(p < r){
		int q= partition(v,p,r);
		quickSort(v, p, q);
		quickSort(v, q+1, r);
	}
}

int main(){
    int vet[100];
    for(int i= 0; i < 100; i++){
        vet[i]= rand() % 100 + 1;
    }
    cout << "Vetor desordenado\n\n";
    for(int i= 0; i < 100; i++){
        cout << vet[i] << " ";
    }
    cout << "\n\nVetor ordenado\n\n";
    quickSort(vet, 0, 99);
    for(int i= 0; i < 100; i++){
        cout << vet[i] << " ";
    }
    cout << "\n";
}
