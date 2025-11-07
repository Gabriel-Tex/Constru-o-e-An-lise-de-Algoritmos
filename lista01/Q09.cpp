#include <bits/stdc++.h>
using namespace std;

int BuscaBinInf(int v[], int x){
    int p = 0, r = 1, mid;

    while(v[r] <= x){
        r = r*2;
    }

    while(p<=r){
        mid = (p+r)/2;

        if(v[mid] == x) return mid;
        if(v[mid] > x) r = mid-1;
        else p = mid+1;
    }
    return -1;

}

int main(){
    int v[] = {2, 5, 7, 89, 123, 167, 176, 232, 341};
    cout << BuscaBinInf(v, 341);

    
    
    return 0;
}