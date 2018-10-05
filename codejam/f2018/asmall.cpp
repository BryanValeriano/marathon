#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool bin(string alvo, vector<string>row) {
    int ini = 0;
    int fim = row.size() - 1;
    while(ini <= fim) {
        int meio = (ini + fim) >> 1;
        //cout << "MEIO: " << row[meio] << endl;
        if(row[meio] > alvo) fim = meio - 1;
        else if(row[meio] < alvo) ini = meio + 1;
        else return true;
    }
    return false;
}

vector<string> constroi(string s, vector<string>row) {
    for(int i = 0; i < s.size(); i++) {
        string tmp;
        int ultimo = 0;
        for(int j = i; j < s.size(); j++) {
            tmp += s[j];
            sort(tmp.begin(), tmp.end());
            row.pb(tmp);
            ultimo++;
        }
    }
    sort(row.begin(), row.end());
    return row;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        int tam; cin >> tam;
        string s1; cin >> s1;
        string s2; cin >> s2;
        vector<string>row1;
        vector<string>row2;
        int resp = 0;
        row1 = constroi(s1, row1);
        row2 = constroi(s2, row2); 
        for(auto id: row1) {
            if(bin(id, row2)) resp++; 
        }
        cout << "Case #" << ++cont << ": " << resp << endl;
    }
               
    return 0;
}

