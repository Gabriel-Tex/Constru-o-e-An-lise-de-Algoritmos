#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// ====================== trocar ======================
void trocar(int v[], int a, int b){
    if(a==b) return;
    v[a] = v[a] ^ v[b];
    v[b] = v[a] ^ v[b];
    v[a] = v[a] ^ v[b];
}

// ====================== Bubble Sort ======================
void bubbleSort(int v[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (v[j] > v[j+1]) {
                trocar(v, j, j+1);
            }
        }
    }
}

// ====================== MAIN ======================
int main(){
    int v[10] = {10,34,2,6,7,9,12,44,23,-4};
    cout << "Vetor nao ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    //bubbleSort(v, 10);
    bubbleSort(v,10);
    
    cout << "Vetor ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}