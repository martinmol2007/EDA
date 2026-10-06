#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Perm;

// Producte s∘t: r[i] = s[t[i]]
Perm producte(const Perm& s, const Perm& t) {
    int n = s.size();
    Perm r(n);
    for (int i = 0; i < n; ++i) r[i] = s[t[i]];
    return r;
}

// Exponenciació ràpida: s^k amb O(log k) productes
Perm potencia(const Perm& s, int k) {
    if (k == 0) {
        // Identitat: (0, 1, ..., n-1)
        Perm id(s.size());
        for (int i = 0; i < s.size(); ++i) id[i] = i;
        return id;
    } else {
        Perm y = potencia(s, k/2);
        if (k % 2 == 0) return producte(y, y);
        else return producte(producte(y, y), s);
    }
}

int main() {
    int n;
    while (cin >> n) {
        Perm s(n);
        for (int i = 0; i < n; ++i) cin >> s[i];
        int k;
        cin >> k;

        Perm r = potencia(s, k);
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ' ';
            cout << r[i];
        }
        cout << endl;
    }
}