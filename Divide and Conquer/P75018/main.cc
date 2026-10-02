#include <iostream>
#include <vector>

using namespace std;

int main() {
    int V, n;

    while(cin >> V && cin >> n && (V != 0 && n != 0)) {
        vector<int> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        

        bool es_possible = false;

        if(es_possible) {
            cout << "married" << endl;
        }
        else {
            cout << "single" << endl;
        }
    }


    return 0;
}