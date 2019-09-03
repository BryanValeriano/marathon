#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int qtd1, qtd2;
    int base1, base2;
    ll val1 = 0;
    ll val2 = 0;
    cin >> qtd1 >> base1;
    int aux;
    ll tmp = 1;
    vector<ll>row1;
    row1.pb(1);
    for(int i = 1; i < qtd1; i++) {
        tmp *= base1;
        row1.pb(tmp);
    }
    int topo = qtd1;
    for(int i = 0; i < qtd1; i++) {
        tmp = row1[--topo];
        cin >> aux;
        val1 += aux * tmp;
    }
    cin >> qtd2 >> base2;
    vector<ll>row2;
    row2.pb(1);
    tmp = 1;
    for(int i = 1; i < qtd2; i++) {
        tmp *= base2;
        row2.pb(tmp);
    }
    topo = qtd2;
    for(int i = 0; i < qtd2; i++) {
        tmp = row2[--topo];
        cin >> aux;
        val2 += aux * tmp;
    }
    if(val1 > val2) cout << ">"; 
    else if(val1 < val2) cout << "<";
    else cout << "=";
    cout << endl;
    //cout << val1 << " " << val2 << endl;
    return 0;
}

