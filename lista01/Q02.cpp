#include <iostream>
using namespace std;
// 565118
int Y(int A[], int p, int r){
    int m = (p+r)/2;
    int u, v;

    if(p==r) return p;
    u = Y(A, p, m);
    v = Y(A, m+1, r);

    if(A[u] < A[v]) return u;
    else return v;
}

int main(){ 
    int v[] = {5,6,5,1,1,8};
    cout << Y(v, 0, 5);
    return 0;
}