#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {    
    string s;
    set<string> palabras;
    int n = 0;

    // PRIMERA ITERACIO, SEMPRE IGUAL
    cin >> s;
    if(s == "END") return 0;
    auto med = palabras.insert(s).first;   // mediana actual
    ++n;
    cout << s << '\n';

    while(cin >> s && s != "END") {
        auto it = palabras.insert(s).first; 
        ++n;

        if(n % 2 == 1) {           
            if(*it > *med) ++med;
        } else {                   
            if(*it < *med) --med;
        }

        cout << *med << '\n';
    }
    
    return 0;
}