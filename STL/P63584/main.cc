#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;


int k_esim(int k, const vector<vector<int> >& V) {
  // Clave: Numero pequeño
  // Valor: First -> A que vector Pertenece
  // Valor: Second -> La pos del vector al que Pertenece
  map<int, pair<int, int>> M;

  // Añadimos el primer elemento de cada vector
  int n = V.size();
  for(int i = 0; i < n; ++i) {
    if(V[i].size() > 0) M.insert({V[i][0], {i, 1}});
  }

  for(int i = 0; i < k-1; ++i) {
    auto it = M.begin();
    // iv es la pos del vector al que pertenece el valor mas pequeño visto hasta ahora
    int iv = it->second.first;
    // j es la posicion dentro del vector iv que hemos de visitar si lo hay
    int j = it->second.second;

    if(V[iv].size() > j) M.insert({V[iv][j], {iv, j+1}});
    M.erase(it);
  }

  return M.begin()->first;
}


int main() {
  int n;
  while (cin >> n) {
    vector<vector<int> > V(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      total += m;
      V[i] = vector<int>(m);
      for (int j = 0; j < m; ++j) cin >> V[i][j];
    }

    int i1, i2, k;
    while (cin >> i1 >> i2 >> k, i1 != -1) {
      if (i1 < 0 or i1 >= n or i2 < 0 or i2 >= n or k < 1 or k > total) {
        cerr << "pifia!!! " << i1 << ' ' << i2 << ' ' << k << ' ' << n
             << ' ' << total << endl;
        return 0;
      }

      swap(V[i1], V[i2]);
      cout << k_esim(k, V) << endl;
    }
  }
}
