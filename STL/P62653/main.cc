#include <iostream>
#include <string>
#include <queue>

using namespace std;

string w;

struct cmp {
    bool operator() (const string& a, const string& b) const {
        if (a.size() != b.size()) return a.size() > b.size();

        string p = w.substr(0, a.size());
        bool ga = a >= p;   // a está en el primer bloque
        bool gb = b >= p;   // b está en el primer bloque

        if (ga != gb) return gb;  // si solo b está en el primer bloque, a sale después
        return a > b;             // mismo bloque: orden lexicográfico normal
    }
};

int main() {
    while(cin >> w) {
        char op;
        int num_t = 0; // Tickets Disponibles
        priority_queue<string, vector<string>, cmp> PQ;

        while(cin >> op && op != 'E') {
            if(op == 'S') {
                string code;
                cin >> code;
                if(num_t > 0) {
                    cout << code << endl;
                    --num_t;
                }
                else {
                    PQ.push(code);
                }
            }
            else {
                if(not PQ.empty()) {
                    cout << PQ.top() << endl;
                    PQ.pop();
                }
                else ++num_t;
            }
        }
        cout << num_t << " ticket(s) left" << endl;
        cout << PQ.size() << " supporter(s) with no ticket" << endl;
        cout << endl;
    }
}