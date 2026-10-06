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

vector<int> permutaciones(vector<int>& v, int k) {
    if(k == 0) return vec_defecto(v.size());
    
    vec_int = permutaciones(v, k/2);

    if(k%2==0);


}

int main() {
    int n;
    while(cin >> n) {
        vector<int>(n);
        for(int i = 0; i < n; ++i) cin >> v[i];

        int k;
        cin >> k;


    }





    return 0;
}