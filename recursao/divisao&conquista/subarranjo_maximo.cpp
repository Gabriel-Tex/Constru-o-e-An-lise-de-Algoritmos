#include <iostream>
#include <windows.h>
#include <climits>
using namespace std;

// struct para o problema do subarranjo máximo
struct Subarray{
    int low;
    int high;
    int sum;
};

// ====================== PROBLEMA DO SUBARRANJO MÁXIMO DIVISAO E CONQUISTA ======================

// função auxiliar que encontra o subarranjo máximo que cruza o ponto médio
Subarray findMaxCrossingSubarray(int v[], int low, int high, int mid){
    int sum = 0;
    // encontrar o subarranjo máximo da esquerda
    int leftSum = INT_MIN; // inicializar a leftSum com o menor valor possível
    int maxLeft;
    for(int i = mid; i >= low; --i){
        sum += v[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    // encontrar o subarranjo máximo da direita
    sum = 0;
    int rightSum = INT_MIN; // inicializar a rightSum com o menor valor possível
    int maxRight;
    for(int i = mid+1;i <= high;++i){
        sum += v[i];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = i;
        }
    }
    return {maxLeft, maxRight, leftSum + rightSum};
}

// função recursiva principal para encontrar o subarranjo máximo 
Subarray findMaximumSubarray(int v[], int low, int high){
    if(low == high) return {low, high, v[low]};
    else{
        int mid = (low + high)/2;
       // (int leftLow, int leftHigh, int leftSum) = findMaximumSubarray(low, mid, v);
       // (int rightLow, int rightHigh, int rightSum) = findMaximumSubarray(mid+1, high, v);
       // (int crossLow, int crossHigh, int crossSum) = findMaxCrossingSubarray(v, low, high, mid);

        Subarray left = findMaximumSubarray(v, low, mid);
        Subarray right = findMaximumSubarray(v, mid+1, high);
        Subarray cross = findMaxCrossingSubarray(v, low, high, mid);

        if(left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        } else if(right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        } else {
            return cross;
        }
    }
}

// ====================== MAIN ======================
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int v[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(v)/sizeof(v[0]);

    Subarray result = findMaximumSubarray(v, 0, n-1);
    cout << "Subarray máximo está entre " << result.low << " e " << result.high << ", com soma = " << result.sum << endl;

    return 0;
}