#include <iostream>
#include <vector>
using namespace std;

int res = 0;
vector<int> sumaFila;
vector<int> sumaColumna;
vector<int> sumaDiag;
int minimoAUsar = 1;

/*bool sumaFilasIguales(vector<vector<int>> &matriz, int k){
    int suma = 0;
    for (int i = 0; i < matriz.size() ; ++i) {
        for (int j = 0; j < matriz.size(); ++j) {
            suma += matriz[i][j];
        }
        if (suma != k) return false;
        suma = 0;
    }
    return true;
}
bool sumaColumIguales(vector<vector<int>> &matriz, int k){
    int suma = 0;
    for (int i = 0; i < matriz.size() ; ++i) {
        for (int j = 0; j < matriz.size(); ++j) {
            suma += matriz[j][i];
        }
        if (suma != k) return false;
        suma = 0;
    }
    return true;

}
bool sumaDiagIguales(vector<vector<int>> &matriz, int k){
    int suma = 0;
    int suma2 = 0;
    for (int i = 0; i < matriz.size() ; ++i) {
        suma += matriz[i][i];
        suma2 += matriz[i][matriz.size()-i-1];
    }
    if (suma != k || suma2 != k) return false;
    return true;
}

bool esCuadMagValido(vector<vector<int>> &matriz){
    int suma = 0;
    for (int i = 0; i < matriz[0].size(); ++i) {
        suma += matriz[0][i];
    }
    return sumaFilasIguales(matriz, suma) && sumaColumIguales(matriz, suma) && sumaDiagIguales(matriz, suma);
}*/

bool esCuadMagicoValido(int n){
    return sumaColumna[sumaColumna.size() - 1] == n && sumaDiag[0] == n;
}

void cantCuadMagicos(vector<vector<int>> &matriz, int i, int j, vector<bool> &usados, int n){
    //-----podas mayor a n-----
    if (i < matriz.size() && j < matriz.size()){
        if(sumaFila[i] > n) return;
        if(sumaColumna[j] > n) return;
    }
    if(sumaDiag[0] > n) return;
    if(sumaDiag[1] > n) return;
    //------------podas distinto a n-----------
    //if (j == 0 && i > 0 && sumaFila[i-1] != n) return;
    if (i == matriz.size() - 1 && j > 0 && sumaColumna[j-1] != n) return;
    if (i == matriz.size() -1 && j == 1 && sumaDiag[1] != n) return;
    //---------------

    if (i == matriz.size()){
        if(esCuadMagicoValido(n)) {
            res++;
        }
    }else{
        int ncuad = matriz.size() * matriz.size();
        int e;
        for (e = minimoAUsar; e <= ncuad; ++e) {
            if (j == matriz.size()-1 && e > n - sumaFila[i]) return;
            if (j == matriz.size()-1){
                e = n - sumaFila[i];
                if (e > ncuad){
                    return;
                }
            }
            if(!usados[e]){
                (matriz)[i][j]=e;
                usados[e] = true;
                if(e == minimoAUsar) minimoAUsar++;
                sumaFila[i]+= e;
                sumaColumna[j]+= e;
                if (i == j) sumaDiag[0]+=e;
                if (i+j == matriz.size()-1) sumaDiag[1] +=e;

                if (j==matriz.size() - 1) {
                    cantCuadMagicos(matriz, i + 1, 0, usados, n);
                }
                else{
                    cantCuadMagicos(matriz, i, j + 1, usados, n);
                }

                usados[e] = false;
                if(e<minimoAUsar){
                    minimoAUsar = e;
                }
                sumaFila[i] -= e;
                sumaColumna[j] -= e;
                if (i == j) sumaDiag[0]-=e;
                if (i+j == matriz.size()-1) sumaDiag[1] -=e;
            }
        }
    }
}

int main() {
    int orden;
    cin>>orden;
    vector<vector<int>> matriz(orden, vector<int>(orden, -1));
    vector<bool> usados(orden*orden+1, false);
    int numeroMagico = (orden*orden*orden + orden)/2; //Sale de la suma de gauss de n^2

    sumaColumna = vector<int>(orden, 0);
    sumaFila = vector<int>(orden, 0);
    sumaDiag = vector<int>(2, 0); //sumaDiag[0] -> "\", sumaDiag[1] -> "/"

    cantCuadMagicos(matriz, 0, 0, usados, numeroMagico);
    cout<<res;
    return 0;
}
