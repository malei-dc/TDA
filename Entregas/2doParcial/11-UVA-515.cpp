#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
#include <string>

using namespace std;

const int INF = INT_MAX;

void agregarAristas(vector<tuple<int, int, int>> &aristas, int desde, int hasta, int peso) {
    aristas.emplace_back(desde, hasta, peso);
}

bool bellmanFord(int n, vector<tuple<int, int, int>> &aristas) {
    vector<int> dist(n, INF);
    dist[0] = 0;  // Nodo ficticio
    for (int i = 1; i < n; ++i) {
        for (const auto& arista : aristas) {
            int desde, hasta, peso;
            tie(desde, hasta, peso) = arista;
            if (dist[desde] != INF && dist[desde] + peso < dist[hasta]) {
                dist[hasta] = dist[desde] + peso;
            }
        }
    }
    for (const auto& arista : aristas) {
        int desde, hasta, peso;
        tie(desde, hasta, peso) = arista;
        if (dist[desde] != INF && dist[desde] + peso < dist[hasta]) {
            return true;  // Ciclo negativo detectado
        }
    }
    return false;
}

int main() {
    int n, m;
    while (cin >> n and n != 0 and cin >> m) {
        vector<tuple<int, int, int>> aristas;

        for (int i = 0; i < m; ++i) {
            int x, y, z;
            string op;
            cin >> x >> y >> op >> z;

            if (op == "gt") {
                agregarAristas(aristas, x + y + 1, x, -z - 1);
            } else if (op == "lt") {
                agregarAristas(aristas, x, x + y + 1, z - 1);
            }
        }

        //agrego arista ficticia para que alcance a todos los nodos y no perderse ningun ciclo
        for (int i = 1; i <= n + 1; ++i) {
            agregarAristas(aristas, 0, i, 0);
        }

        bool result = bellmanFord(n + 2, aristas);  // n + 2 porque estamos usando un nodo ficticio y contando desde 1

        if (result) {
            cout << "successful conspiracy" << endl;
        } else {
            cout << "lamentable kingdom" << endl;
        }
    }

    return 0;
}
