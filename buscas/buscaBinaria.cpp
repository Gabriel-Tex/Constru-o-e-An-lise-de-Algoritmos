#include <iostream>
#include <vector>
using namespace std;

// busca binária recursiva
int BuscaBin(int v[], int p, int r, int valor){
    if(r<p){
        cout << "o valor " << valor << " nao esta no vetor" << endl;
        return -1;
    }
    
    int mid = (p+r)/2;

    if(v[mid] == valor){
        cout << "o valor " << valor << " esta na posicao " << mid << endl;
        return mid;
    }
    else if(v[mid] < valor){
        return BuscaBin(v, mid+1, r, valor);
    }
    else{
        return BuscaBin(v, p, mid-1, valor);
    }
}

// busca binária iterativa
int BuscaBinIt(int v[], int n, int valor){
    int inicio = 0, fim = n-1;
    

    while(inicio <= fim){
        int mid = (inicio+fim)/2;

        if(v[mid] == valor){
            cout << "o valor " << valor << " esta na posicao " << mid << endl;
            return mid;
        }
        else if(v[mid] < valor){
            inicio = mid+1;
        }
        else{
            fim = mid-1;
        }
    }
    cout << "o valor " << valor << " nao esta no vetor" << endl;
    return -1;
}

int main(){
    int v[10] = {-4, 2, 6, 7, 9, 10, 12, 23, 34, 44};
    BuscaBinIt(v, 10, 34);

    return 0;
}