#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// ====================== trocar ======================
void trocar(int v[], int a, int b){
    if(a==b) return;
    v[a] = v[a] ^ v[b];
    v[b] = v[a] ^ v[b];
    v[a] = v[a] ^ v[b];
}

// ====================== Heap de máximo ======================
// Para o elemento da posição i: 
int parent(int i){
    return ((i-1)/2);
}

int left(int i){
    return (2*i + 1);
}

int right(int i){
    return (2*i + 2);
}

// manter a propriedade heap de máximo
void mantemHeap(int v[], int i, int n){
    int l = left(i), r = right(i), maior;

    if(l < n && v[l] > v[i]){
        maior = l;
    }
    else
        maior = i;
    
    if(r < n && v[r] > v[maior])
        maior = r;
    
    if(maior != i){
        trocar(v, i, maior);
        mantemHeap(v, maior, n);
    }
}

void constroiHeap(int v[], int n){
    for(int j = n/2-1; j>=0; --j)
        mantemHeap(v, j, n-1);
}

void heapSort(int v[], int n){
    constroiHeap(v, n);

    for(int i = n-1; i>0; --i){
        trocar(v, 0, i);
        n -= 1;
        mantemHeap(v, 0, n);
    }
}

// ====================== MAIN ======================
int main(){
    int v[10] = {10,34,2,6,7,9,12,44,23,-4};
    cout << "Vetor nao ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    heapSort(v, 10);
    
    cout << "Vetor ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}