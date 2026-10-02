#include <iostream>
#include <vector>

using namespace std;

void binary_search(const vector<int>& v, int l, int r, int x, int& posible) {
    if(l <= r) {
        int m = (l + r)/2;
        int num = x + v[m];
        if(num == m+1) {
            posible = m+1;
            binary_search(v, l, m-1, x, posible);
        } 
        else if(num > m+1) {
            binary_search(v, l, m-1, x, posible);
        }
        else {
            binary_search(v, m+1, r, x, posible);
        }
    } 
}

int main() {
    int cnt = 1;
    int n;

    while(cin >> n) {
        // Crea S y leelo
        vector<int> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int m;
        cin >> m;

        // Crea A y leelo
        vector<int> a(m);
        for(int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        cout << "Sequence #" << cnt << endl;

        for(int i = 0; i < m; ++i) {
            int posible = -1;
            binary_search(v, 0, v.size()-1, a[i], posible);

            if(posible != -1) {
                cout << "fixed point for " << a[i] << ": " << posible << endl;
            } else {
                cout << "no fixed point for " << a[i] << endl;
            }
        }

        cout << endl;

        ++cnt;
    }


    return 0;
}