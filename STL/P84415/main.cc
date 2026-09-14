#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    
    // Mapa ordenado lexicograficamente y sus veces que sale dicha palabra
    map<string, int> pal_vec;
    
    while(cin >> s) {
        if(s == "minimum?") {
            if(pal_vec.empty()) cout << "indefinite minimum" << endl;
            else {
                auto it = pal_vec.begin();
                string palabra = it->first;
                int num = it->second;

                cout << "minimum: " << palabra << ", " << num << " time(s)" << endl;
            }
        }
        else if(s == "store") {
            string palabra;
            cin >> palabra;

            ++pal_vec[palabra];
        }
        else if(s == "delete") {
            string palabra;
            cin >> palabra;

            auto it = pal_vec.find(palabra);
            if(it != pal_vec.end()) {
                --pal_vec[palabra];
                if(it->second == 0) pal_vec.erase(it);
            }
        }
        else {
            // maximum?
            if(pal_vec.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = pal_vec.rbegin();
                string palabra = it->first;
                int num = it->second;

                cout << "maximum: " << palabra << ", " << num << " time(s)" << endl;
            }
        }
    }

    return 0;
}