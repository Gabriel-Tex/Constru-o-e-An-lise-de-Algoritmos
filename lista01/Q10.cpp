#include <bits/stdc++.h>
using namespace std;

int mediana(int x[], int y[], int n){
    int p = 0, r = n-1, i = 0, f = n-1;
    
    while(p<=r && i<=f){
        int q = (p+r)/2;
        int m = (i+f)/2;

        if(m+q == n-1 && x[q] >= y[m-1] && y[m] >= x[q-1]){
            return (x[q] + y[m])/2;
        }
        
    }

}

int main(){
    int v[] = {2, 5, 7, 89, 123, 167, 176, 232, 341};
    

    
    
    return 0;
}