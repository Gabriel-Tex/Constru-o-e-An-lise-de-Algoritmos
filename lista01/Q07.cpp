#include <bits/stdc++.h>
using namespace std;


void imprimir(int v[], int n){
    for(int i=0;i<n;++i)
        cout << v[i] << " ";
    cout << endl;
}

int buscaQuat(int v[], int n, int x){
    int inicio = 0, fim = n-1;
    int k, l, m;

    while(inicio <= fim){
        k = inicio + (fim - inicio) / 4;
        l = inicio + (fim - inicio) / 2;
        m = inicio + 3 * (fim - inicio) / 4;

        if(v[k] == x) return k;
        if(v[l] == x) return l;
        if(v[m] == x) return m;

        if(x < v[k]) fim = k-1;
        else if(x > v[k] && x < v[l]){
            inicio = k+1;
            fim = l-1;
        }
        else if(x > v[l] && x < v[m]){
            inicio = l+1;
            fim = m-1;
        }
        else if (x > v[m]) inicio = m+1;
    }
    return -1;
}


int main(){
    int v[10] = {-2, 5, 12, 23, 34, 36, 76, 87, 88, 92};
    cout << buscaQuat(v, 10, 13);


    return 0;
}