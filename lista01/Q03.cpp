#include <bits/stdc++.h>
using namespace std;

void trocar(int v[], int a, int b){
    if(a==b) return;
    v[a] = v[a] ^ v[b];
    v[b] = v[a] ^ v[b];
    v[a] = v[a] ^ v[b];
}

void X(int A[], int i, int j){
    if(A[i] > A[j]) trocar(A, i, j);
    if (i+1>=j) return;
    int k = (j-i+1)/3;
    X(A, i, j - k);
    X(A, i + k, j);
    X(A, i, j - k);
}
int main(){
    int v[10] = {15, 42, 21, 50, 33, 65, 40, 43, 20};
    cout << "Vetor nao ordenado: " << endl;
    for(int i = 0; i<9; ++i)
        cout << v[i] << " ";
    cout << endl;
    X(v, 0, 8);
    
    cout << "Vetor ordenado: " << endl;
    for(int i = 0; i<9; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
    return 0;
}