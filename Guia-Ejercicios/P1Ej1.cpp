#include <iostream>
#include <vector>
using namespace std;

//Dado un multiconjunto C = {c1 , . . . , cn } de números naturales y un natural k , queremos
//determinar si existe un subconjunto de C cuya sumatoria sea k . Vamos a suponer fuertemente
//que C está ordenado de alguna forma arbitraria pero conocida (i.e., C está implementado como
//la secuencia c1 , . . . , cn o, análogamente, tenemos un iterador de C )

//variables globales
vector<int> indices;
vector<vector<int>> subconj;
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
            indices[i-1]=0;
            subsetSum(C, i-1, j);
            if (res==true)
                subconj.push_back(indices);
            res = false;

            indices[i-1]=1;
            subsetSum(C, i-1, j-C[i-1]);
            if (res==true)
                subconj.push_back(indices);
            res = false;
    }
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> C = vector<int>(n,0);
    indices = vector<int>(n,0);
    while (n>0){
        int i= C.size();
        int value;
        cin>>value;
        C[i-n] = value;
        n--;
    }

    subsetSum(C, C.size(), k);

    cout<< (subconj.size()>0) <<endl;

        for (int i = 0; i < subconj.size(); ++i) {
            for (int j = 0; j < subconj[i].size(); ++j) {
                cout<<C[j]*subconj[i][j]<<" ";
            }
            cout<< endl;
        }

    /*SALIDA: Si es true, devuelve 1 y los indices de la solucion parcial EJ: C=[6,12,6] k = 12 devuelve "0 12 0" y "6 0 6" (el primero que encuentra)
            si es false devuelve solo 0
     */
    return 0;
}
