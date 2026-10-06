#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

void salida(const map<int, int>& m, double& media) {
    int min = m.begin()->first;
    int max = (--m.end())->first;
    cout << "minimum: " << min << ", maximum: " << max << ", average: " << media << endl;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    // Clave: Numero. Valor: Veces Repetido
    map<int, int> m;

    string s;

    double suma, total, media;
    suma = total = media = 0;

    while(cin >> s) {
        if(s == "number") {
            int x;
            cin >> x;

            suma += x;
            total += 1;
            media = suma/total;

            // Añade el numero
            m[x]++;

            salida(m, media);
        }
        else {
            // Es s == "delete"
            if(!m.empty()) {
                auto it = m.begin();
                
                suma -= it->first;
                total -= 1;
                media = suma/total;

                int repes = it->second;

                if(repes == 1) m.erase(it);
                else           m[it->first]--;

                if(!m.empty()) salida(m, media);
                else cout << "no elements" << endl;
            }
            else {
                cout << "no elements" << endl;
            }
        }
    }

    return 0;
}
