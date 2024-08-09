#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

typedef int tiempo;
typedef int piso;

const int inf = 1e8;

int dijkstra (int s, int t, int tamañoAdj, vector<vector<pair<int, int>>> &adj, int ascensores) {

    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;

    vector<int> dist(tamañoAdj, inf);
    dist[s] = 0;

    pq.push({0, s});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int l = it.second;

            if (d + l < dist[adjNode]) {
                dist[adjNode] = d + l;
                pq.push({dist[adjNode], adjNode});
            }
        }

    }
    int res = inf;
    for (int i = 0; i < ascensores; ++i) {
        res = min(res, dist[t+100*i]);
    }
    return res;
}


int main() {
    int ascensores, destino;
    while (cin>>ascensores>>destino) {
        vector<vector<pair<piso, tiempo>>> adj(100* ascensores);
        /* lista de adyacencias de todos los ascensores
         * 0~99 -> lista del ascensor 1
         * 100~199 -> lista del ascensor 2
         * 200~299 -> lista del ascensor 3
         * ...
         */

        //ingreso los costos por piso de cada ascensor
        vector<int> costoPorPiso(ascensores);
        for (int & i : costoPorPiso) {
            cin>> i;
        }
        //ingreso los pisos accesibles de cada ascensor
        cin.ignore();
        vector<vector<int>> relaciones(ascensores);
        for (int i = 0; i < ascensores; ++i) {
            string str;
            getline(cin, str);
            stringstream ss(str);
            int valor;
            while (ss >> valor) {
                relaciones[i].push_back(valor);
            }
        }
        //conectar el grafo (ambas direcciones)
        for (int i = 0; i < ascensores; ++i) {
            for (int j = 0; j < relaciones[i].size() - 1; ++j) {
                piso PActual = relaciones[i][j];
                piso PSiguiente = relaciones[i][j + 1];
                tiempo actual = (PSiguiente - PActual) * costoPorPiso[i];
                adj[PActual+100*i].push_back({PSiguiente+100*i, actual});
                adj[PSiguiente+100*i].push_back({PActual+100*i, actual});
            }
        }
        //pisos compartidos (ambas direcciones)
        for (int i = 0; i < ascensores; ++i) {
            for (int j = 0; j < relaciones[i].size(); ++j) {
                piso PActual = relaciones[i][j];
                for (int k = i + 1; k < ascensores; ++k) {
                    if (PActual != 0 and adj[PActual+100*k].size() > 0) {
                        adj[PActual+100*k].push_back({PActual+100*i,60});
                        adj[PActual+100*i].push_back({PActual+100*k, 60});
                    }
                }
            }
        }

        //recorro todos los pisos 0
        int res = inf;
        for (int i = 0; i < ascensores; ++i) {
            int estaIteracion = dijkstra(0+100*i, destino, 100 * ascensores, adj, ascensores);
            if (estaIteracion < res) {
                res = estaIteracion;
            }
        }
        if (res == inf)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
