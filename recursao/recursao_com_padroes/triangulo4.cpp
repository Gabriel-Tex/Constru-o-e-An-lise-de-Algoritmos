#include <bits/stdc++.h>
using namespace std;

// ======================== maneira 1 ========================
// ao entrar um número par, o programa não funciona (roda infinitamente)
void triangulo4(int n, int k){
    if (n == 1) {
        for (int i = 0; i <= k; ++i)
            cout << " ";
        cout << "*" << endl;
        return;
    }

    for (int i = 0; i <= k; ++i)
        cout << " ";
    for (int i = 1; i <= n; ++i)
        cout << "*";
    cout << endl;

    triangulo4(n - 2, k + 1);

    for (int i = 0; i <= k; ++i)
        cout << " ";
    for (int i = 1; i <= n; ++i)
        cout << "*";
    cout << endl;
}

// ======================== maneira 2 ========================
void __triangulo4(int n, int k){
    if(n==1){
        for(int i = 1; i <= k; i++) printf(" ");
        printf("*\n");
    }else{
        for(int i = 1; i <= k; i++) printf(" ");
        for(int i = 1; i <= 2*n-1; i++) printf("*");
        printf("\n");
        __triangulo4(n-1, k+1);
        for(int i = 1; i <= k; i++) printf(" ");
        for(int i = 1; i <= 2*n-1; i++) printf("*");
        printf("\n");
    }
}
int main() {
    triangulo4(7, 0);
    return 0;
}
