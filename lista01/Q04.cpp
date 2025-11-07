#include <iostream>
using namespace std;

int buscaLinearRec(int v[], int p, int r, int k){
    if(p > r) return -1;
    if(v[p] == k) return p;
    return buscaLinearRec(v, p+1, r, k);
}

int main(){
    int v[10] = {10,34,2,6,7,9,12,44,23,-4};
    cout << buscaLinearRec(v, 0, 9, 13);
    return 0;
}