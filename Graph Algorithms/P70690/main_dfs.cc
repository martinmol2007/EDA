#include <iostream>
#include <vector>

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
    if(pos_valida(f, c, n, m) && T[f][c] != 'X') {
        if(T[f][c] == 't') return true;
        T[f][c] = 'X';
        // Adyacentes
        for(Pos d : dir) {
            int xseg = f + d.first;
            int yseg = c + d.second;

            if(trobar_tresor(T, n, m, xseg, yseg)) return true;
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