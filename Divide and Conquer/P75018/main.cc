#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binary_search(const vector<int>& v, int l, int r, int x, int& pos) {
    if(l <= r) {
        int m = (l + r)/2;
        if(v[m] == x) pos = m;
        else if(v[m] > x) binary_search(v, l, m-1, x, pos);
        else              binary_search(v, m+1, r, x, pos);
    }
}

int main() {
    int V, n;

    while(cin >> V >> n && (V != 0 && n != 0)) {
        // Lee el Vector v y lo ordena
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());

        // Inicia la busqueda si es posible que se de V
        bool es_possible = false;
        int k = 0;
        while(k < n && v[k] < V && !es_possible) {
            // Numero que falta
            int falta = V - v[k];
            int pos = -1;
            binary_search(v, 0, n-1, falta, pos);
            if(pos != -1) {
                if(pos != k) es_possible = true;
                else if((pos > 0 && v[pos-1] == v[k]) || (pos < n-1 && v[pos+1] == v[k])) es_possible = true;
            }
            
            ++k;
        }

        cout << (es_possible ? "married" : "single") << endl;
    }
    return 0;
}