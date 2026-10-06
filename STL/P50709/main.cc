#include <iostream>
#include <map>

using namespace std;

int main() {
    char letra;
    // Clave: El numero. Valor: Veces repetido
    map<int, int> m;

    while(cin >> letra) {
        if(letra == 'A') {
            // Consulta el número més gran.
            if(!m.empty()) {
                auto it = m.end();
                --it;
                cout << it->first << endl;
            } 
            else {
                cout << "error!" << endl;
            }
        }
        else if(letra == 'R') {
            // Esborra el número més gran (un d’ells, si està repetit).
            if(!m.empty()) {
                auto it = m.end();
                --it;
                
                int repes = it->second;
                if(repes == 1) {
                    m.erase(it);
                } 
                else {
                    (it->second)--;
                }
            }
            else {
                cout << "error!" << endl;
            }
        }
        else if(letra == 'S') {
            // Guarda una còpia del número x donat.
            int x;
            cin >> x;

            m[x]++;
        }
        else if(letra == 'I') {
            // Incrementa el número més gran (un d’ells, si està repetit) en x unitats.
            int x;
            cin >> x;
            if(!m.empty()) {
                auto it = m.end();
                --it;

                int num = it->first;
                int repes = it->second;

                if(repes == 1) {
                    m.erase(it);
                } else {
                    --m[num];
                }

                m[num+x]++;
            }
            else {
                cout << "error!" << endl;
            }
        }
        else {
            // D: Decrementa el número més gran (un d’ells, si està repetit) en x unitats.
            int x;
            cin >> x;
            if(!m.empty()) {
                auto it = m.end();
                --it;

                int num = it->first;
                int repes = it->second;

                if(repes == 1) {
                    m.erase(it);
                } else {
                    --m[num];
                }

                m[num-x]++;
            }
            else {
                cout << "error!" << endl;
            }
        }
    }

    return 0;
}