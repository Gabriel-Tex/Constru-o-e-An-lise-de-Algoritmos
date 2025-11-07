#include <iostream>
#include <vector>
using namespace std;

// busca linear
int BuscaLinear(int v[], int tamanho, int valor){
    int posicao;
    for(int i=0; i<tamanho; ++i){
        if (v[i] == valor){
            posicao = i;
            cout << "o valor " << valor << " esta na posicao " << posicao << endl;
            return posicao;
        }
    }
    cout << "o valor " << valor << " nao esta no vetor" << endl;
    return -1;
}

int main(){
    int v[10] = {-4, 2, 6, 7, 9, 10, 12, 23, 34, 44};
    BuscaLinear(v, 10, 34);

    return 0;
}