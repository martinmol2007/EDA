#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int>& v, int l, int r, int x, int& pos) {
    if(l <= r) {
        int m = (l + r)/2;
        if(v[m] == x) {
            pos = m;
            return true;
        }
        else if(v[m] > x) return binary_search(v, l, m-1, x, pos);
        else return binary_search(v, m+1, r, x, pos);
    }

    return false;
}

int main() {
    int V, n;

    while(cin >> V && cin >> n && (V != 0 && n != 0)) {
        // Lee el Vector
        vector<int> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        bool es_possible = false;

        int k = 0;
        while(k < v.size() && v[k] < V && not es_possible) {
            int falta = V-v[k];
            int pos = -1;
            if(binary_search(v, 0, v.size()-1, falta, pos)) {
                if(pos != k) {
                    es_possible = true;
                }
                else {
                    if((pos > 0 && v[pos-1] == v[k]) or (pos <= v.size()-1 && v[pos+1] == v[k])) {
                        es_possible = true;
                    }
                }
            }

            ++k;
        }

        if(es_possible) {
            cout << "married" << endl;
        }
        else {
            cout << "single" << endl;
        }
    }


    return 0;
}