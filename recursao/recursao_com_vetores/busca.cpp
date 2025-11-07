#include <bits/stdc++.h> 
using namespace std;

// informa apenas se o elemento k está ou não no vetor
int busca(int vet[], int n, int k){
    if(n==1){
        return (vet[0] == k);
    }else{
        int t = busca(vet, n-1, k);
        if(t == 1){
            return 1;
        }else{
            return vet[n-1] == k;
        }
    }
}

int main(){
    int v[] = {1, 4, 7, 12, 3, -1, 5};
    cout << busca(v, 7, 12);
    return 0;
}
