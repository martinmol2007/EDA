#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

// Definicion de Grafo
typedef vector<vector<int>> Grafo;

void ordenacion_topologica(Grafo& g, vector<int>& ge, vector<int>& sol) {
    int n = g.size();
    // AHORA MIN HEAP; POR DEFECTO MAX HEAP
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < n; ++i) {
        if(ge[i] == 0) pq.push(i);
    }

    while(not pq.empty()) {
        int u = pq.top();
        pq.pop();
        sol.push_back(u);
        for(int v : g[u]) {
            if(--ge[v] == 0) pq.push(v);
        }
    }

    return;
}

int main() {
    int n, m;

    while(cin >> n >> m) {
        Grafo g(n);
        vector<int> ge(n, 0);   // Aprovechamos para leer grados de entrada
        for(int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            ++ge[y];
        }
        vector<int> sol;
        ordenacion_topologica(g, ge, sol);

        /* HAY CICLO
        if(sol.size() < n) 
        */
        for(int i = 0; i < n; ++i) {
            if(i != 0) cout << " ";
            cout << sol[i];
        }
        cout << endl;
    }


    return 0;
}