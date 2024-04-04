#include <iostream>
#include <vector>
using namespace std;

vector<bool> usados;
vector<int> solucion;
vector<vector<int>> matriz;
vector<int> res;
int minimo = 99999999999;

void mostrarRes(vector<int> &res){
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int hacerCuentaEcuacion(vector<vector<int>> &matriz,  vector<int> &solucion){
    int res = matriz[solucion[solucion.size()-1]][solucion[0]];
    for (int i = 0; i < solucion.size()-1; ++i) {
        res = res + matriz[solucion[i]][solucion[i+1]];
    }
    return res;
}


void calcularMin(vector<vector<int>> &matriz, vector<bool> &usados, vector<int> &solucion, int n){
    if (solucion.size() == n){
        int minParcial = hacerCuentaEcuacion (matriz, solucion);
        if (minParcial < minimo){
            res.clear();
            minimo = minParcial;
            res = solucion;
        }
    }
    else{
        for (int i = 0; i < n; ++i) {
            int indice = i%n;
            if (!usados[indice]){
                usados[indice] = true;
                solucion.push_back(indice);
                calcularMin(matriz, usados, solucion, n);
                usados[indice] = false;
                solucion.pop_back();
            }
        }
    }
}

int main() {
    cout<<"ingresar n"<<endl;
    int n; cin>>n;
    usados = vector<bool>(n, false);
    matriz = vector<vector<int>>(n, vector<int>(n,0));
    cout<<"rellenar matriz"<<endl;
    int valorMatriz;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>valorMatriz;
            matriz[i][j] = valorMatriz;
        }
    }

    calcularMin(matriz, usados, solucion, n);
    mostrarRes(res);
    cout<<"valor que minimiza: "<< minimo;

    return 0;
}
