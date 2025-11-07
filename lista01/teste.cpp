#include <bits/stdc++.h>
using namespace std;

int elementoMajoritario(const vector<int>& v) {
    int candidato = -1, count = 0;
    int n = v.size();

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidato = v[i];
            count = 1;
        } else if (v[i] == candidato) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == candidato)
            count++;
    }

    if (count > n / 2)
        return candidato;
    return -1;
}

int main() {
    vector<int> v{2, 2, 1, 1, 2, 2, 3};
    int majoritario = elementoMajoritario(v);

    if (majoritario != -1)
        cout << "Elemento majoritário: " << majoritario << endl;
    else
        cout << "Nenhum elemento majoritário" << endl;

    return 0;
}
