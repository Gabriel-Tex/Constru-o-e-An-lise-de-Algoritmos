#include <iostream>
using namespace std;

int X(int n){
    if(n==0) return 1;
    return n*X(n-1);
}

int main(){
    int a = X(4);
    cout << a;
    return 0;
}