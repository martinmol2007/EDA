#include <iostream>
#include <set>
#include <string>

using namespace std;

struct comp {
    bool operator() (const string& a, const string& b) const {
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
};

int main() {
    int cont = 1;
    string op;

    while(op != "QUIT") {
        set<string> HAS;
        set<string, comp> HAD;

        while(cin >> op and op != "END" and op != "QUIT") {
            auto it = HAS.find(op);
            if(it != HAS.end()) {
                // ESTA EN HAS
                HAS.erase(it);
                HAD.insert(op);
            }
            else {
                // NO ESTA EN HAS
                HAS.insert(op);
                HAD.erase(op);
            }
        }
        if(cont > 1) cout << endl;
        
        cout << "GAME #" << cont << endl;
        cout << "HAS:" << endl;

        for(const string& s: HAS) cout << s << endl;

        cout << endl << "HAD:" << endl;
        
        for(const string& s: HAD) cout << s << endl;

        ++cont;
    }

    return 0;
}