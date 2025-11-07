#include <bits/stdc++.h>
using namespace std;

typedef struct par{
    int x, y;
} par;

par maior_e_segundo_maior(int v[], int n){
    par p;
    if(n==2){
        if(v[0] >= v[1]){
            p.x = v[0];
            p.y = v[1];
        }
        else{
            p.x = v[1];
            p.y = v[0];
        }
        return p;
    }
    else{
        p = maior_e_segundo_maior(v, n-1);

        if(p.x <= v[n-1]){
            p.y = p.x;
            p.x = v[n-1];
        }
        else if(p.y <= v[n-1]){
            p.y = v[n-1];
        }
        return p;
    }
}

int main(){
    int v[] = {1, 4, 7, 12, 3, -1, 5};
    par m = maior_e_segundo_maior(v, 7);
    cout << m.x << ", " << m.y;
    return 0;
}