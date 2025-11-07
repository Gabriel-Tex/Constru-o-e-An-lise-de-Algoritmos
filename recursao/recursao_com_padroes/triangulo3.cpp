#include <bits/stdc++.h>
using namespace std;

void triangulo3(int n, int k){
    if(n==1){
        for(int i = 0; i<=k; ++i)
            cout << " ";
        cout << "*" << endl;
    }
    else{       
        for(int i = 0; i<=k; ++i){
            cout << " ";
        }
        for(int i = 1; i <= n; ++i){
            cout << "*";
        }
        cout << endl;

        triangulo3(n-1, k+1);
        
        for(int i = 0; i<=k; ++i){
            cout << " ";
        }
        for(int i = 1; i <= n; ++i){
            cout << "*";
        }
        cout << endl;
    }
    
}


int main(){
    triangulo3(4, 0);
    return 0;
}