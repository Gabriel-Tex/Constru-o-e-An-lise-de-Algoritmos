#include <iostream>
#include <random>
#include <vector>
using namespace std;

// ====================== trocar ======================
void trocar(int v[], int a, int b){
    if(a==b) return;
    v[a] = v[a] ^ v[b];
    v[b] = v[a] ^ v[b];
    v[a] = v[a] ^ v[b];
}

// ====================== sortear ======================

int sortear(int a, int b){
    random_device rd;                
    mt19937 gen(rd());               
    uniform_int_distribution<> dist(a, b);

    return dist(gen);
}

// ====================== QuickSort ======================
int particiona(int v[], int p, int r, int pivot){
    int i = p-1;
    for(int j = p; j < r; ++j){
        if(v[j] <= pivot){
            ++i;
            trocar(v, i, j);
        }
    }
    trocar(v, i+1, r);
    return i+1;
}

void quickSort(int v[], int p, int r){
    int q, i, pivot;
    if(p >=  r) return;

    i = sortear(p,r);
    trocar(v, i, r);
    pivot = v[r];

    q = particiona(v, p, r, pivot);
    quickSort(v, p, q-1);
    quickSort(v, q+1, r);
}

// ====================== MAIN ======================
int main(){
    int v[10] = {10,34,2,6,7,9,12,44,23,-4};

    cout << "Vetor nao ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;

    quickSort(v,0,9);
    
    cout << "Vetor ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}