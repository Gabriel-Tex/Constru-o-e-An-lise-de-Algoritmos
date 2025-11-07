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

// ====================== achar menor e maior ======================
int acharMenor(int v[], int n, int inicio){
    int posicaoMenor = inicio, menor = v[inicio];
    for(int i = inicio; i<n; ++i){
        if(menor > v[i]){
            menor = v[i];
            posicaoMenor = i;
        }
    }
    return posicaoMenor;
}

int acharMaior(int v[], int n, int inicio){
    int posicaoMaior = inicio, maior = v[inicio];
    for(int i = inicio; i<n; ++i){
        if(maior < v[i]){
            maior = v[i];
            posicaoMaior = i;
        }
    }
    return posicaoMaior;
}

// ====================== Selection Sort ======================
void selectionSort(int v[], int n){
    int anterior, posicaoMenor, inicio = 0;
    while(inicio < n-1){
        posicaoMenor = acharMenor(v, n, inicio);
        anterior = v[inicio];
        v[inicio] = v[posicaoMenor];
        v[posicaoMenor] = anterior;
        ++inicio;
    }
}

void selectionSortCompacto (int v[], int n){
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(v[i] > v[j]){
                trocar(v, i, j);
            }
        }
    }
}

// selection sort recursivo
void selectionSortRec(int v[], int n){
    if(n>1){
        int maior = acharMaior(v, n, 0);
        trocar(v, maior, n-1);
        selectionSortRec(v, n-1);
    }
}
// ====================== MAIN ======================
int main(){
    int v[10] = {10,34,2,6,7,9,12,44,23,-4};
    cout << "Vetor nao ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    //bubbleSort(v, 10);
    selectionSortRec(v,10);
    
    cout << "Vetor ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}