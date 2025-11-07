#include <bits/stdc++.h>
using namespace std;

void losango(int n, int k){
    if(n==k){
        for(int i=0;i<2*k-1; ++i){
            cout << "*";
        }
        cout << endl;
    }
    else{
        for(int i=0;i<n-k;++i){
            cout << " ";
        }
        for(int i=0;i<2*k-1;++i){
            cout << "*";
        }
        cout << endl;

        losango(n, k+1);

        for(int i=0;i<n-k;++i){
            cout << " ";
        }
        for(int i=0;i<2*k-1;++i){
            cout << "*";
        }
        cout << endl;
    }
    
}

void losango2(int n, int k) {
    if(k>n){
        return;
    }
    else{
        for(int i = 1; i <= n-k; i++)
            printf(" ");
        for(int i = 1; i <= 2*k-1; i++)
            printf("*");
        printf("\n");

        losango2(n, k+1);

        for(int i = 1; i <= n-k; i++)
            printf(" ");
        for(int i = 1; i <= 2*k-1; i++)
            printf("*");
        printf("\n");
    }
}
int main(){
    losango(5, 1);
    return 0;
}