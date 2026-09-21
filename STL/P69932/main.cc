#include <iostream>

#include <sstream>
#include <set>

using namespace std;

bool es_par(int num) {
    return num%2 == 0;
}

bool es_impar(int num) {
    return not es_par(num);
}

int main() {
    string s;

    while(getline(cin, s)) {
        set<int> set;

        istringstream iss(s);
        
        int x;
        while(iss >> x) {
            set.insert(x);
        }
        // Aqui ya tendriamos que tenerlo ordenado de manera creciente y sin repetidos 

        // Casos Directos, si esta vacio o solo tiene 1 elemento
        if(set.empty()) {
            cout << "0" << endl;
        }
        else if(set.size() == 1) {
            cout << "1" << endl;
        }
        else {
            // Contador de la secuencia mas larga
            int cnt = 1;
            
            // Sabemos que el size es 2 o mas grande
            auto it = set.begin();
            auto it2 = it;
            ++it2;

            while(it2 != set.end()) {
                int num1 = *it;
                int num2 = *it2;
                if(es_par(num1)) {
                    if(es_par(num2)) {
                        ++it2;
                    }
                    else {
                        ++cnt;
                        it = it2;
                        ++it2;
                    }
                }
                else {
                    if(es_impar(num2)) {
                        ++it2;
                    }
                    else {
                        ++cnt;
                        it = it2;
                        ++it2;
                    }
                }
            }

            cout << cnt << endl;
        }
    }

    return 0;
}