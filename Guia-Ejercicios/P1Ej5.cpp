#include <iostream>
#include <vector>
using namespace std;

//Dado un multiconjunto C = {c1 , . . . , cn } de números naturales y un natural k , queremos
//determinar si existe un subconjunto de C cuya sumatoria sea k . Vamos a suponer fuertemente
//que C está ordenado de alguna forma arbitraria pero conocida (i.e., C está implementado como
//la secuencia c1 , . . . , cn o, análogamente, tenemos un iterador de C )

//variables globales
vector<int> C;
vector<vector<int>> memo;
bool res = false;

void subsetSum(vector<int> &C, int i, int j){

    if (i==0 && j==0){
        res = true;
        return;
    }
    else if(i==0 && j!=0){
        res = false;
        return;
    }
    else{
        if (memo[i][j] != -1){
            res = memo[i][j];
            return;
        }
        subsetSum(C, i-1, j);
        memo[i][j]=res;
        if (res== true)
            return;
        subsetSum(C, i-1, j-C[i-1]);
        memo[i][j]=res;
        if (res==true)
            return;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    C = vector<int>(n);
    memo = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));

    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }

    //usando memo
    subsetSum(C, n, k);
    cout<<res;

    /*SALIDA: Si es true, devuelve 1 y los indices de la solucion parcial EJ: C=[6,12,6] k = 12 devuelve "0 12 0" y "6 0 6" (el primero que encuentra)
            si es false devuelve solo 0
     */
    return 0;
}