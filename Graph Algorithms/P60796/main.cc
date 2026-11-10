#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definiion: Tablero
typedef vector<vector<char>> Tablero;

// First: Posicion (First: Fila Second: Columna)
// Second: Distancia
typedef pair<pair<int, int>, int> PosDis;

// Vector de direcciones
const vector<PosDis> dir = {{{-1, 0}, 1}, {{0, 1}, 1}, {{1, 0}, 1}, {{0, -1}, 1}};

bool pos_valida(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int trobar_tresor(Tablero& T, int n, int m, int f, int c) {
    queue<PosDis> Q;
    // Usaremos T para indicar Visitados, poniendo X en el camino
    Q.push({{f, c}, 0});
    T[f][c] = 'X';

    while(not Q.empty()) {
        PosDis act = Q.front();
        Q.pop();

        // Adyacentes
        for(int i = 0; i < 4; ++i) {
            int xseg = act.first.first + dir[i].first.first; 
            int yseg = act.first.second + dir[i].first.second;
            
            if(pos_valida(xseg, yseg, n, m) and T[xseg][yseg] != 'X') {
                if(T[xseg][yseg] == 't') return act.second+1;
                Q.push({{xseg, yseg}, act.second+1});
                T[xseg][yseg] = 'X';    // Marcamos a visitado
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    Tablero T(n, vector<char>(m));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> T[i][j];
        }
    }

    int f, c;
    cin >> f >> c;

    int res = trobar_tresor(T, n, m, f-1, c-1);
    res == -1 ? cout << "no es pot arribar a cap tresor" : cout << "distancia minima: " << res;
    cout << endl;

    return 0;
}
