#include <bits/stdc++.h>
using namespace std;

void trocar(int v[], int a, int b){
    if(a==b) return;
    v[a] = v[a] ^ v[b];
    v[b] = v[a] ^ v[b];
    v[a] = v[a] ^ v[b];
}

void imprimir(int v[], int n){
    for(int i=0;i<n;++i)
        cout << v[i] << " ";
    cout << endl;
}

// =================== versão 1 ===================
void par_impar(int v[], int n){
    for(int i = 0;i<n-1;++i){
        for(int j = i+1;j<n;++j){
            if(i%2 == 0 && j%2==0){
                if(v[i]>v[j])
                    trocar(v, i, j);
            }
            else if(i%2 == 1 && j%2 == 1){
                if(v[i]>v[j])
                    trocar(v, i, j);
            }
        }
    }
}

// =================== versão 2 ===================

void ordena_par_impar(int v[], int n) {
    vector<int> pares, impares;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            pares.push_back(v[i]);
        else
            impares.push_back(v[i]);
    }

    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end());

    int p = 0, q = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            v[i] = pares[p++];
        else
            v[i] = impares[q++];
    }
}

int main(){
    int v[10] = {10,34,13,6,21,9,12,44,23,-5};
    par_impar(v, 10);
    imprimir(v, 10);
    ordena_par_impar(v, 10);
    
    
    return 0;
}