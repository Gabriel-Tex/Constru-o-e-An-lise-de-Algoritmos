#include <bits/stdc++.h> 
using namespace std;

void trocar(int v[], int a, int b){
    if(a==b) return;
    v[a] = v[a] ^ v[b];
    v[b] = v[a] ^ v[b];
    v[a] = v[a] ^ v[b];
}
// informa apenas se o elemento k está ou não no vetor
int maior_pos(int v[], int n){
    if(n==1){
        return 0;
    }else{
        int m = maior_pos(v, n-1);
        return v[m] > v[n-1] ? m : n-1;
    }
}

// selection sort recursivo
void ordena(int v[], int n){
    if(n>1){
        int pos = maior_pos(v, n);
        //troca o maior com o ultimo
        trocar(v, pos, n-1);
        ordena(v, n-1);
    }
}


int main(){
    int v[] = {1, 4, 7, 12, 3, -1, 5};
    ordena(v, 7);
    for(int i = 0; i<7; ++i){
        cout << v[i] << " ";
    }
    return 0;
}
