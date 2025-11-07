#include <bits/stdc++.h>
using namespace std;

void triangulo(int n){
    if(n==1){
        cout << "*" << endl;
    }
    else{
        for(int i = 1; i<=n; ++i){
            cout << "*";
        }
        cout << endl;

        triangulo(n-1);

        for(int i = 1; i<=n; ++i){
            cout << "*";
        }
        cout << endl;
    }
    
}

int main(){
    triangulo(4);
    return 0;
}