#include <bits/stdc++.h>
using namespace std;

void triangulo2(int n, int k){
    if(n==k){
        for(int i = 1; i <= n; ++i){
            cout << "*";
        }
        cout << endl;
    }
    else{
        for(int i = 1; i <= k; ++i){
            cout << "*";
        }
        cout << endl;

        triangulo2(n, k+1);
        
        for(int i = 1; i <= k; ++i){
            cout << "*";
        }
        cout << endl;
    }
    
}


int main(){
    triangulo2(4, 1);
    return 0;
}