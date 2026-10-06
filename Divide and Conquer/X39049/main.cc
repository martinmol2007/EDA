#include <iostream>
#include <vector>

using namespace std;

vector<int> vec_defecto(int n) {
    vector<int> v(n);
    for(int i = 0; i < n; ++i) v[i] = i;
    return v;
}

vector<int> permuta(const vector<int>& vx, const vector<int>& vy) {
    int n = vx.size();
    vector<int> res(n);
    for(int i = 0; i < n; ++i) {
        int num = vy[i];
        res[i] = vx[num];
    }
    return res;
}

vector<int> permutaciones(const vector<int>& v, int k) {
    if(k == 0) return vec_defecto(v.size());
    else {
        vector<int> y = permutaciones(v, k/2);

        if(k%2==0) return permuta(y, y);
        else       return permuta(permuta(y, y), v);
    }

}

int main() {
    int n;
    while(cin >> n) {
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];

        int k;
        cin >> k;

        vector<int> res = permutaciones(v, k);
        for(int i = 0; i < n; ++i) {
            if(i > 0) cout << ' ';
            cout << res[i];
        }
        cout << endl;
    }

    return 0;
}