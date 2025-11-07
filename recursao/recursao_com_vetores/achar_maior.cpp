#include <bits/stdc++.h>
using namespace std;

int acharMaior(int v[], int n){
    if(n==1) return v[0];
    else{
        int m = acharMaior(v, n-1);
        if(m < v[n-1]){
            m = v[n-1];
            return m;
        }
        else{
            return m;
        }
    }
}

int main(){
    int v[] = {1, 4, 7, 12, 3, -1, 5};
    cout << acharMaior(v, 7);
    return 0;
}