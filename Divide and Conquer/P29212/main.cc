#include <iostream>

using namespace std;

long long exponenciacio_rapida(long long x, long long n, int m) {
    if(n == 0) return 1;
    else {
        long long y = exponenciacio_rapida(x, n/2, m);
        if(n%2==0) return y*y%m;
        else       return (y*y%m)*x%m; 
    }
}

int main() {
    int n, k, m;
    
    while(cin >> n >> k >> m) {
        long long pot = exponenciacio_rapida(n, k, m);  

        cout << pot << endl;
    }

    return 0;
}