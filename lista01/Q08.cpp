#include <bits/stdc++.h>
using namespace std;

int buscaBinAlt(int v[], int n, int x) {
    int inicio = 0, fim = n-1, primeira_ocorrencia = -1, posicao_possivel = -1;

    while (inicio <= fim) {
        int mid = (inicio+fim)/2;

        if (v[mid] == x){
            primeira_ocorrencia = mid;  
            fim = mid-1;    
        }
        else if (x < v[mid]){
            posicao_possivel = mid;
            fim = mid - 1;
            
        }
        else {
            posicao_possivel = mid;
            inicio = mid + 1;
        }
    }
    if(v[primeira_ocorrencia] == x) return primeira_ocorrencia;
    return posicao_possivel;
}


int main(){
    int v[] = {0,2,2,2,5,7,9,12};
    cout << buscaBinAlt(v, 8, 13);
    
    
    return 0;
}