#include <iostream>
#include <vector>

using namespace std;


void first_occurrence_aux(double x, const vector<double>& v, int l, int r, int& pos) {
    if(l <= r) {
        int m = (l+r)/2;
        if(v[m] == x) {
            pos = m;
            first_occurrence_aux(x, v, l, m-1, pos);
        }
        else if(v[m] < x) first_occurrence_aux(x, v, m+1, r, pos);
        else first_occurrence_aux(x, v, l, m-1, pos);
    } 
}

int first_occurrence(double x, const vector<double>& v) {
    int pos = -1;
    first_occurrence_aux(x, v, 0, v.size()-1, pos);
    return pos;
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
