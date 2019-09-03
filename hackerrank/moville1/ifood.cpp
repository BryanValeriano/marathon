#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
map<string, int> indice;

void addn(string name) {
    map<string, int>:: iterator it;
    it = indice.find(name);
    if(it != indice.end()) indice[name]++;
    else indice.insert(mk(name, 1));
}

int busc(string name) {
    map<string, int>:: iterator it;
    it = indice.find(name);
    if(it != indice.end()) return it->sec;
    else return 0;
}

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        string oper;
        string name;
        char tmp;
        cin >> tmp;
        oper += tmp;
        while(tmp != ':') {
            cin >> tmp;
            oper += tmp;
        }
        getline(cin, name);

        if(oper[0] == 'a') {
            string aux;
            for(int i = 0; i < name.size(); i++) {
                aux += name[i];
                //cout << "teste: " << aux << endl;
                addn(aux);
            }
        }
                
        else cout << busc(name) << endl;
    }

    return 0;
}

