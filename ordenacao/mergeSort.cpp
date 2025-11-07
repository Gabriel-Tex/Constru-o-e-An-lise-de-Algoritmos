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

// ====================== Merge Sort ======================
// responsável pela ordenação
void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int v[]){
    int i = 0; // índice do vetor principal
    int l = 0, r = 0; // índices, respectivamente, do leftArray e do rightArray

    // enquanto ambos contiverem elementos, ordene-os
    while(l < leftSize && r < rightSize){
        if(leftArray[l] < rightArray[r]){
            v[i] = leftArray[l];
            ++l;
        } else {
            v[i] = rightArray[r];
            ++r;
        }
        ++i;
    }
    // se ainda restarem elementos no lado esquerdo
    while(l < leftSize){
        v[i] = leftArray[l];
        ++i;
        ++l;
    }
    // se ainda restarem elementos no lado direito
    while(r < rightSize){
        v[i] = rightArray[r];
        ++i;
        ++r;
    }

}
// responsável pela divisão do array 
void mergeSort(int v[], int n){
    // caso base
    if(n<=1) return;

    int mid = n/2;

    // cria dois vetores auxiliares, um para o subconjunto esquerdo e outro pro direito
    int leftArray[mid], rightArray[n-mid];

    // preenche os subconjuntos esquerdo e direito
    int i = 0, j = 0;
    for(;i<n;++i){
        if(i < mid){
            leftArray[i] = v[i];
        }
        else {
            rightArray[j] = v[i];
            ++j;
        }
    }

    // recursão (divisão e conquista)
    mergeSort(leftArray, mid);
    mergeSort(rightArray, n-mid);
    merge(leftArray, mid, rightArray, n-mid, v);
}

// versão do kormen
void intercala(int v[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;  

    // criação de dois vetores, left e right
    int leftArray[n1+1];
    int rightArray[n2+1];

    for(int i = 0;i<n1;++i)
        leftArray[i] = v[p+i];
    for(int i = 0;i<n2;++i)
        rightArray[i] = v[q+1+i];
    
    // sentinela
    leftArray[n1] = INT_MAX;
    rightArray[n2] = INT_MAX;

    // ordenação com intercalação
    int i=0;
    int j = 0;
    for(int k = p; k<=  r; ++k){
        if(leftArray[i] <= rightArray[j]){
            v[k] = leftArray[i];
            ++i;
        }
        else{
            v[k] = rightArray[j];
            ++j;
        }
    }
        
}

void mergeSortKormen(int v[], int p, int r){
    int q;
    // verificar se o vetor ainda possui tamanho maior que 1
    if (p < r){
        q = (p+r)/2;
        mergeSortKormen(v, p, q);
        mergeSortKormen(v,q+1, r);
        intercala(v, p, q, r);
    }
}

// mergeSort iterativo

void mergeSortIt(int v[], int n){
    int p, r, b = 1;
    while(b < n){
        p = 0;
        while(p + b < n){
            r = p + 2*b - 1;
            if (r >= n) r = n - 1;
            intercala(v, p, p+b-1, r);
            p = p + 2*b;
        }
        b = 2*b; // dobra o tamanho do bloco
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
    mergeSortIt(v,10);
    
    cout << "Vetor ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}