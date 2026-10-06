#include <iostream>
#include <vector>
using namespace std;

bool binary_search(const vector<int>& v, int l, int r, int x) {
    if(l > r) return false;
    int m = (l+r)/2;
    if(v[m] == x) return true;
    else if(v[m] < x) return binary_search(v, m+1, r, x);
    else              return binary_search(v, l, m-1, x);
}

// Suponemos que r acaba en el penultimo indice valido (v.size()-2)
int busqueda_medio(const vector<int>& v, int l, int r) {
    if(l <= r) {
        int m = (l+r)/2;
        if(v[m] > v[m+1]) return m;
        else if(v[m] > v[v.size()-1]) {
            // Estamos a la izquierda
            return busqueda_medio(v, m+1, r);
        }
        else if(v[m] < v[0]) {
            // Estamos en la derecha
            return busqueda_medio(v, l, m-1);
        }
    }

    // No deberia pasar
    return -1;
}

bool search(int x, const vector<int>& v) {
    int medio = busqueda_medio(v, 0, v.size()-2);
    return binary_search(v, 0, medio, x) || binary_search(v, medio+1, v.size()-1, x);
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}
