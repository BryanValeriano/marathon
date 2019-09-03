#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
    return a.fi < b.fi;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    ll A = 0;
    ll B = 0;
    vector< pair<int,int> >row;
    for(int i = 1; i <= n; i++) {
        int aux; cin >> aux;
        row.pb(mp(aux, i));
    }
    sort(row.begin(), row.end(), cmp);
    int m; cin >> m;
    while(m--) {
        int q; cin >> q;
        int ini = 0; int fim = n-1;
        while(ini <= fim) {
            int meio = (ini+fim)>>1;
            if(row[meio].fi < q) ini = meio + 1;
            else if(row[meio].fi > q) fim = meio - 1;
            else { A += row[meio].se; B += n+1 - row[meio].se; break; }
        }
    }
    cout << A << " " << B << endl;

    return 0;
}

