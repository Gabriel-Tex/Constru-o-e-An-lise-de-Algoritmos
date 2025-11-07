#include <bits/stdc++.h>
using namespace std;

// ====================== versao O(n) utilizando matriz ======================

int intervalos_invertidos(vector<vector<int>>intervalos, int ncol){
    int i=0, cont = 0;
    
    for(int j = 0; j<ncol-1; ++j){
        if(intervalos[i][j+1] < intervalos[i+1][j])
            ++cont;
    }
    return cont;
}

// ====================== versao O(n) utilizando pares ======================

int intervalos_invertidos2(const vector<pair<int,int>>& intervalos) {
    int cont = 0;
    int n = intervalos.size();
    
    for (int j = 0; j < n - 1; ++j) {
        if (intervalos[j + 1].first < intervalos[j].second)
            ++cont;
    }

    return cont;
}

// ====================== versao O(nlogn) com divisão e conquista  ======================

int intervalos_invertidos3(const vector<pair<int, int>>& intervalos)
{


}

int main(){
// ====================== chamada 1 ======================

    int ncol = 5;
    vector<vector<int>> intervalos(2, vector<int>(ncol)); 

    intervalos[0][0] = 1;
    intervalos[1][0] = 3;
    
    intervalos[0][1] = 6;
    intervalos[1][1] = 7;

    intervalos[0][2] = 4;
    intervalos[1][2] = 5;

    intervalos[0][3] = 10;
    intervalos[1][3] = 12;

    intervalos[0][4] = 8;
    intervalos[1][4] = 9;

    cout << intervalos_invertidos(intervalos, ncol) << endl;

// ====================== chamada 2 ======================

    vector<pair<int,int>> intervalos2 = {
        {1, 3}, {6, 7}, {10, 12}
    };

    cout << intervalos_invertidos2(intervalos2) << endl; 
 
    return 0;
}