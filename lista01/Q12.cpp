#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int>& A, int x){
    int n = A.size(), p, r, q;

    for(int i = 0; i<n; ++i){
        p = i+1, r = n-1;
        while(p<=r){
            q = (p+r)/2;
            if(A[i] + A[q] == x){
                return true;
            }
            if(A[i] + A[q] < x) p = q+1;
            else r = q-1;
        }
    }
    return false;
}
int main(){
        vector<int> v{2, 5, 12, 23, 34, 36, 76, 87, 88, 92};
        cout << twoSum(v, 10) << endl; 
 
    return 0;
}