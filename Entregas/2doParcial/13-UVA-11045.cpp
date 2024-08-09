#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
enum Talla { XXL, XL, L, M, S, XS };
Talla convertir(const string& input) {
    if (input == "XXL") return XXL;
    if (input == "XL") return XL;
    if (input == "L") return L;
    if (input == "M") return M;
    if (input == "S") return S;
    if (input == "XS") return XS;
}

int bfs(int s, int t, vector<int>& parent, vector<vector<int>>& adj, vector<vector<int>>& capacity) {
    fill(parent.begin(), parent.end(), -1);  // Inicializa el vector parent a -1
    parent[s] = -2;  // Nodo fuente no tiene padre
    queue<pair<int, int>> q;
    q.push({s, INF});  // Empieza la BFS con el nodo fuente y flujo infinito

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t, int n, vector<vector<int>>& adj, vector<vector<int>>& capacity) {
    int flow = 0;
    vector<int> parent(n, -1);
    int new_flow;

    while ((new_flow = bfs(s, t, parent, adj, capacity)) != 0) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    int test;
    cin >> test;
    while (test --) {
        int n, m;
        cin >> n >> m; //n cant de tshirt, m personas

        int cantidadShirts = n/6;
        int cantNodos = 6 + m + 2; //6 tallas, m personas, nodos fuente y sumidero
        int fuente = cantNodos - 2;
        int sumidero = cantNodos -1;

        vector<vector<int>> capacidad(cantNodos, vector<int>(cantNodos, 0));
        vector<vector<int>> adj(cantNodos); //0~5 talles, 6~ 6+m personas, fuente, sumidero

        //conecto fuente con cada talle, peso: cantidad de shirts
        for (int i = 0; i < 6; ++i) {
            capacidad[fuente][i] = cantidadShirts;
            adj[i].push_back(fuente);
            adj[fuente].push_back(i);
        }

        //conecto cada persona con el sumidero, peso: 1
        for (int i = 0; i < m; ++i) {
            capacidad[6+i][sumidero] = 1;
            adj[6+i].push_back(sumidero);
            adj[sumidero].push_back(6+i);
        }

        //conecto la preferencia de cada persona con la talla de input, peso: 1
        for (int i = 0; i < m; ++i) {
            string talla1, talla2;
            cin >> talla1 >> talla2;
            Talla id1 = convertir(talla1);
            Talla id2 = convertir(talla2);

            capacidad[id1][6+i] = 1;
            adj[id1].push_back(6+i);
            adj[6+i].push_back(id1);

            capacidad[id2][6+i] = 1;
            adj[id2].push_back(6+i);
            adj[6+i].push_back(id2);
        }
        int flow = maxflow(fuente, sumidero, cantNodos, adj, capacidad);

        if (flow == m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
