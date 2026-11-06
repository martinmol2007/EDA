#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DEF: Grafo
typedef vector<vector<int>> Grafo;

vector<int> BFS(const Grafo& G) {
    vector<int> res;
    queue<int> Q;               // Se guardan los nodos que se pueden visitar
    int n = G.size();           // Numero de vertices
    vector<bool> vis(n, false); // Para Evitar Bucles Infinitos
    
    for(int u = 0; u < n; ++u) { // Por si el grafo es no connexo
        if(not vis[u]) {
            Q.push(u);

            vis[u] = true;

            while(not Q.empty()) {
                int act = Q.front();
                Q.pop();
        
                res.push_back(act);
        
                // Añadir adyacentes de act
                for(int v : G[act]) {   // for(int i = 0; i < G[act].size(); ++i) int v = G[act][i]
                    if(not vis[v]) {
                        Q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }   
    }
    
    return res;
}