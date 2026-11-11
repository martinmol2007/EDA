#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DEF: Tablero
typedef vector<vector<char>> Tablero;

// First: Fila
// Second: Columna
typedef pair<int, int> Pos;

// Vector de direcciones
const vector<Pos> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool pos_valida(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

bool trobar_tresor(Tablero& T, int n, int m, int f, int c) {
    queue<Pos> Q;
    // Usaremos T para indicar Visitados, poniendo X en el camino
    Q.push({f, c});
    T[f][c] = 'X';

    while(not Q.empty()) {
        Pos act = Q.front();
        Q.pop();

        // Adyacentes
        for(int i = 0; i < 4; ++i) {
            int xseg = act.first + dir[i].first; 
            int yseg = act.second + dir[i].second;

            if(pos_valida(xseg, yseg, n, m) and T[xseg][yseg] != 'X') {
                if(T[xseg][yseg] == 't') return true;
                Q.push({xseg, yseg});
                T[xseg][yseg] = 'X';    // Marcamos a visitado
            }
        }
    }

    return false;
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

    if(trobar_tresor(T, n, m, f-1, c-1)) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}