#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<vector<pair<int, int>>, int>> output;
int tiempo = 0;

bool comparar(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;  // Si los segundos componentes son iguales, ordenar por el primero
    }
    return a.second > b.second;   // Ordenar por el segundo componente en orden descendente
}

void dfs(vector<vector<int>> &adj, int vertice, vector<bool> &visitados){
    visitados[vertice] = true;
    for (auto hijo: adj[vertice]){
        if (!visitados[hijo]){
            dfs(adj, hijo, visitados);
        }
    }
}

void calculoCC(vector<vector<int>> &adj, int &cant, int vertice){
    int estaciones = adj.size();
    vector<bool> visitados(estaciones, false);
    if (vertice != -1)
        visitados[vertice] = true; //saco el vertice
    for (int i = 0; i < estaciones; ++i) {
        if (!visitados[i]){
            dfs(adj, i, visitados);
            cant++;
        }
    }
}

void dfs_articulaciones(vector<vector<int>> &adj, int vertice, vector<bool> &visitados, vector<bool> &articulacion,
                        vector<int> &padres, vector<int> &low, vector<int> &descubrimiento){
    int hijos = 0;
    visitados[vertice] = true;
    descubrimiento[vertice] = low[vertice] = tiempo++;
    for(auto siguiente: adj[vertice]){
        if(!visitados[siguiente]){
            padres[siguiente] = vertice;
            hijos++;
            dfs_articulaciones(adj, siguiente, visitados, articulacion, padres, low, descubrimiento);
            low[vertice] = min(low[vertice], low[siguiente]);
            // (1) Si vertice es raíz y tiene más de un hijo
            if (padres[vertice] == -1 and hijos > 1)
                articulacion[vertice] = true;
            // (2) Si vertice no es raíz y el valor bajo del hijo es mayor o igual al descubrimiento del vertice
            if (padres[vertice] != -1 and low[siguiente] >= descubrimiento[vertice])
                articulacion[vertice] = true;
        }
        else if(siguiente != padres[vertice])
            // Actualizar low[vertice] considerando la vuelta al antecesor
            low[vertice] = min(low[vertice], descubrimiento[siguiente]);
    }
}

void calculoArticulaciones( vector<vector<int>> &adj, vector<bool> &articulacion){
    int estaciones = adj.size();
    vector<bool> visitados(estaciones, false);
    vector<int> descubrimiento(estaciones, 0);
    vector<int> low(estaciones, 0);
    vector<int> padres(estaciones, -1);

    for (int i = 0; i < estaciones; ++i) {
        if (!visitados[i]){
            dfs_articulaciones(adj, i, visitados, articulacion, padres, low, descubrimiento);
        }
    }
}

int main() {
    while (1) {
        //ingreso datos
        int estaciones, cantObjs;
        cin >> estaciones >> cantObjs;
        if (estaciones == 0 and cantObjs == 0) break;
        vector<vector<int>> adj = vector<vector<int>>(estaciones);
        while (1) {
            int x, y;
            cin >> x >> y;
            if (x == -1 and y == -1) break;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        /* 1° voy a buscar todos los puntos de articulación
         * 2° calculo la cantidad de componentes conexas original
         * 3° por cada punto de articulacion calculo la cantidad de componentes conexas sin el vertice
         * */
        //---------------calculo puntos de articulacion---------------
        vector<bool> articulacion = vector<bool>(estaciones, false);
        calculoArticulaciones(adj, articulacion);
        //----------------calculo cc original---------------------------
        int cc = 0;
        calculoCC(adj, cc, -1);
        //---------------calculo cc por cada punto de articulacion------------
        vector<pair<int, int>> salida;
        for (int i = 0; i < estaciones; ++i) {
            if (articulacion[i]){
                int articulacionCC = 0;
                calculoCC(adj, articulacionCC, i);
                salida.push_back({i, articulacionCC});
            }
            else
                salida.push_back({i, cc});
        }
        sort(salida.begin(), salida.end(), comparar);
        output.push_back({salida, cantObjs});
    }
    //imprimo resultados
    for (int i = 0; i < output.size(); ++i) {
        for (int j = 0; j < output[i].second; ++j) {
            int estacion = output[i].first[j].first;
            int valor_paloma = output[i].first[j].second;
            cout<< estacion <<" "<< valor_paloma <<endl;
        }
        cout<<endl;
    }
    return 0;
}
