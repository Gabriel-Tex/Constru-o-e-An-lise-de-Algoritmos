#include <bits/stdc++.h>
using namespace std;

typedef struct par{
    int q1, q2;
}par;

void imprimir(int v[], int n){
    for(int i=0;i<n;++i)
        cout << v[i] << " ";
    cout << endl;
}

par pamonha(int v[], int p, int r, int piv){
    par idx;
    int n = r-p+1;
    vector<int> menor_piv;
    vector<int> igual_piv;
    vector<int> maior_piv;

    for(int i = 0; i<n; ++i){
        if(v[i] < piv){
            menor_piv.push_back(v[i]);
        }
        else if(v[i] == piv){
            igual_piv.push_back(v[i]);
        }
        else{
            maior_piv.push_back(v[i]);
        }
    }
    idx.q1 = menor_piv.size() - 1;
    idx.q2 = igual_piv.size() + menor_piv.size() - 1;

    int a = 0, b = 0;
    for(int i = 0; i<n; ++i){
        if(i <= idx.q1){
            v[i] = menor_piv[i];
        }
        else if(i <= idx.q2){
            v[i] = igual_piv[a];
            ++a;
        }
        else{
            v[i] = maior_piv[b];
            ++b;
        }
    }
    return idx;
}

int main(){
    int v[10] = {10,34,13,6,21,9,12,44,23,-5};
    par teste = pamonha(v, 0, 9, 12);
    cout << "indices: [" << teste.q1 << ", " << teste.q2 << "]" << endl;
    imprimir(v, 10);
    return 0;
}