#include <iostream>
#include <vector>
using namespace std;

vector<bool> solucion;
vector<int> res;
int maximo;

void mostrarRes(vector<int> &res){
    for (int i = 0; i < res.size(); ++i) {
            cout<<res[i]<<" ";
    }
}

int calcular(vector<vector<int>> &matriz, vector<bool> &solucion){
    int res = 0;
    for (int i = 0; i < solucion.size(); ++i) {
        for (int j = i; j < solucion.size(); ++j) {
            if (solucion[i] && solucion[j])
                res += matriz[i][j];
        }
    }
    return res;
}

void calcularMax(vector<vector<int>> &matriz, vector<bool> &solucion, int k, int tamañoResActual){
    if (tamañoResActual == k){
        int maxParcial = calcular(matriz, solucion);
        if (maxParcial>maximo){
            res.clear();
            maximo = maxParcial;
            for (int i = 0; i < solucion.size(); ++i) {
                if (solucion[i]){
                    res.push_back(i);
                }
            }
        }
    }
    else{
        for (int i = 0; i < solucion.size(); ++i) {
            if (!solucion[i]){
                solucion[i] = true;
                tamañoResActual++;
                calcularMax(matriz, solucion, k, tamañoResActual);
                solucion[i] = false;
                tamañoResActual--;
            }
        }
    }
}

int main() {
    cout<<"ingresar orden y k"<<endl;
    int orden, k;
    cin>>orden>>k;

    solucion = vector<bool>(orden, false);
    vector<vector<int>>matriz(orden, vector<int>(orden,0));

    int valorMatriz;
    for (int i = 0; i < orden; ++i) {
        for (int j = i; j < orden; ++j) {
            cin>>valorMatriz;
            matriz[i][j] = valorMatriz;
        }
    }

    calcularMax(matriz, solucion, k, 0);
    mostrarRes(res);
    return 0;
}
