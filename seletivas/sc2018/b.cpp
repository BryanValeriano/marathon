#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    bool chagas = true;
    int n; cin >> n;
    char aux;
    string row; 
    cin >> aux;
    char first = aux;
    row += aux;
    vector<int>poss;
    int resp = 0;
    for(int i = 1; i < n; i++) {
        cin >> aux;
        row += aux;
        if(aux < first) {
            resp = 1;
        }
        else if(aux == first) {
            poss.pb(i);
        }
    }
    if(resp == 1) { cout << "No" << endl; return 0; } 
    if(poss.size() != 0 && poss.size() != n-1) {
        int tam = poss.size();
        for(int i = 0; i < tam && chagas; i++) {
            string tmp = row.substr(poss[i], n);          
            tmp += row.substr(0, poss[i]);
            //cout << tmp << " " << row << endl;
            if(tmp < row){ chagas = false; } 
        }
    }   
    cout << (chagas ? "Yes" : "No") << endl;
    
    
    return 0;
}

