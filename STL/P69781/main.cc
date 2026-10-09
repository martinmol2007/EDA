#include <iostream>
#include <unordered_map>

const int MAX = 1e8;

using namespace std;

int main() {
    int x, y, n;

    while(cin >> x >> y >> n) {
        // First: Valor
        // Second: Posicion
        unordered_map<int, int> m;
        int pos = 1;

        m.insert({n, 0});
        bool repe = false;
        auto it = m.begin();


        while(not repe && n <= MAX) {
            if(n%2 == 0) n = n/2 + x;
            else n = 3*n + y;

            it = m.find(n);
            if(it == m.end()) m.insert({n, pos});
            else repe = true;
            ++pos;
        }
        

        if(repe) cout << pos - (it->second) -1 << endl;
        else cout << n << endl;
    }

    return 0;
}