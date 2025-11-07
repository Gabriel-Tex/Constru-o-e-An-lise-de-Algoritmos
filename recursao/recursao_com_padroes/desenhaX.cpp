#include <bits/stdc++.h>
using namespace std;

void desenhaAux(int k, int espacoAntes, int espacoMeio){
    if(k==1){
        for(int i=0;i<espacoAntes;++i){
            cout << " ";
        }
        cout << "*" << endl;
    }
    else{
        for(int i=0;i<espacoAntes;++i){
            cout << " ";
        }

        cout << "*";

        for(int i=0;i<espacoMeio;++i){
            cout << " ";
        }

        cout << "*" << endl;

        desenhaAux(k-1, espacoAntes+1, espacoMeio-2);

        for(int i=0;i<espacoAntes;++i){
            cout << " ";
        }

        cout << "*";

        for(int i=0;i<espacoMeio;++i){
            cout << " ";
        }

        cout << "*" << endl;
    }
}

void desenhaX(int n){
    desenhaAux(n, 0, 2*n-3);
}

int main(){
        desenhaX(5);
    return 0;
}