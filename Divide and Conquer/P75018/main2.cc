#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hay_boda(const vector<int>& v, int V, int l, int r) {
    if(l >= r) return false;
    if(v[l]+v[r] == V) return true;
    else if(v[l]+v[r] > V) return hay_boda(v, V, l, r-1);
    else return                   hay_boda(v, V, l+1, r);
}

int main() {
    int V, n;

    while(cin >> V >> n && (V != 0 && n != 0)) {
        // Lee el Vector v y lo ordena
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());

        // Inicia la busqueda si es posible que se de V
        bool es_possible = hay_boda(v, V, 0, n-1);

        cout << (es_possible ? "married" : "single") << endl;
    }
    return 0;
}