#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Declaracion del numero infinito
const int INF = numeric_limits<int>::max();

// FIRST: Peso de un arco 
// SECOND: Nodo al que va
typedef pair<int, int> ArcP;

// Lista de adyacencia de un grafo con pesos
typedef vector<vector<ArcP>> GrafArcP;

void Dijkstra(const GrafArcP& G, int s, vector<int>& d) {
    int n = G.size();
    d[s] = 0;
    vector<bool> vis(n ,false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> Q;
    Q.push(ArcP(0, s));

    while(not Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        if(not vis[u]) {
            vis[u] = true;
            for(ArcP a : G[u]) {
                int v = a.second;
                int dis = a.first;
                if(d[v] > d[u] + dis) {
                    d[v] = d[u] + dis;
                    Q.push(ArcP(d[v], v));
                }
            }
        }
    }
    return;
} 

int main() {
    int n, m;

    while(cin >> n >> m) {
        GrafArcP G(n);
        for(int i = 0; i < m; ++i) {
            int nodo_salida, nodo_llegada, peso_arco;
            cin >> nodo_salida >> nodo_llegada >> peso_arco;

            G[nodo_salida].push_back(ArcP(peso_arco, nodo_llegada));
        }
            
        int nodo_inicial, nodo_final;
        cin >> nodo_inicial >> nodo_final;

        vector<int> d(n, INF);
        Dijkstra(G, nodo_inicial, d);

        if(d[nodo_final] == INF) {
            cout << "no path from " << nodo_inicial << " to " << nodo_final << endl;
        }
        else {
            cout << d[nodo_final] << endl;
        }
    }

    return 0;
}