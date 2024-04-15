#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> memo;
const int inf = 99999999;

int minimoCosto (vector<int> &cortes, int desde, int hasta){
    if (desde + 1 == hasta)
        return 0;
    if (memo[desde][hasta] == -1) {
        int m = cortes[cortes.size() - 1]; // max cost
        for (int k = desde + 1; k < hasta; k++) {
            m = min(m, minimoCosto(cortes, desde, k) + minimoCosto(cortes, k, hasta));
        }
        memo[desde][hasta] = (cortes[hasta] - cortes[desde]) + m;
    }
    return memo[desde][hasta];
}


int main() {
    cout<<"Ingresar tamaño y cantidad de cortes: ";
    int tamaño, cantcortes; cin >> tamaño>> cantcortes;
    cout<<"Ingresar posiciones de corte (1 a "<< tamaño - 1 << "): ";
    vector<int> cortes;
    for (int i = 0; i < cantcortes; ++i) {
        int numero;
        cin>>numero; cortes.push_back(numero);
    }
    sort(cortes.begin(), cortes.end());
    memo = vector<vector<int>>(cantcortes, vector<int>(cantcortes, -1));
    int res =  minimoCosto(cortes, 0, cortes.size()-1);

    cout<<"El minimo costo es: "<<res;
    return 0;
}
