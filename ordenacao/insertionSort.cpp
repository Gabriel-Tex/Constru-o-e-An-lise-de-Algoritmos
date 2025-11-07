#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// ====================== Insertion Sort ======================
void insertionSort (int v[], int n) {
        for(int j=1; j<n; ++j){
            int chave = v[j];
            int i = j - 1;
            while(i >= 0 && v[i] > chave){
                v[i + 1] = v[i];
                i = i - 1;
            v[i + 1] = chave;    
            }
        }
    }

void reverseInsertionSort(int v[], int n){
    for(int j=1; j<n; ++j){
        int chave = v[j];
        int i = j - 1;
        while(i >= 0 && v[i] < chave){
            v[i + 1] = v[i];
            i = i - 1;
        v[i + 1] = chave;    
        }
    }
}

void insertionSortRec(int v[], int i, int n){
    if(i >= n) return;
    
    int aux, j = i;
    aux = v[j];

    while(j>0 && aux < v[j-1]){
        v[j] = v[j-1];
        --j;
    }
    v[j] = aux;
    insertionSortRec(v, i+1, n);
}
// ====================== MAIN ======================
int main(){
    int v[10] = {10,34,2,6,7,9,12,44,23,-4};
    cout << "Vetor nao ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    //bubbleSort(v, 10);
    insertionSortRec(v,1,10);
    
    cout << "Vetor ordenado: " << endl;
    for(int i = 0; i<10; ++i)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}