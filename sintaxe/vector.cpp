#include <iostream>
#include <vector>
using namespace std;


void imprimirVetor(vector <int> vetor){
    cout << "Elementos do vetor: " << endl; 
    int tamanho = vetor.size();
    for(int i = 0; i < tamanho; ++i){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main (){

    // criando vetor
    vector <int> vetor (12); 
    // imprimindo o tamanho do vetor
    cout << "Tamanho do vetor: " << vetor.size() << endl;
    // adicionar elemento no final
    vetor.push_back(3);
    // adicionar elemento no começo
    vetor.insert(vetor.begin(), 5);
    // adicionar elemento em posição arbitrária
    vetor.insert(vetor.begin() + 1, 8);

    // imprimir vetor
    imprimirVetor(vetor);
    // cria uma cópia de vetor
    vector <int> vetor2(vetor);
    imprimirVetor(vetor2);

    vector<int> vetor3(13);
    // atribui o vetor ao vetor3
    vetor3 = vetor;
    imprimirVetor(vetor3);
    return 0;
}