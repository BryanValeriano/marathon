#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 5;

map<ii,int> g;
vector<int> v[T];
vector<int> u[T];
vector<int> d[T];
int freq[T];
bool vis[T];

bool inter(int a, int b, int z) {
    for(auto aa : u[a])
        for(auto bb : d[b])
            if(aa == bb and aa == z) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n-2; i++) {
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        for(int j = 0; j < 3; j++) {
            freq[a[j]]++;
            for(int k = j+1; k < 3; k++) {
                g[mk(a[j],a[k])]++;
                g[mk(a[k],a[j])]++;


            }
        }
    }

    for(auto ok : g) {
        int j,k;
        j = ok.fi.fi;
        k = ok.fi.se;
        v[j].pb(k);
        v[k].pb(j);
        if(ok.se == 1) {
            u[j].pb(k);
            u[k].pb(j);
        } else {
            d[j].pb(k);
            d[k].pb(j);
        }
    }

    int ini = 0;
    int fim = 0;

    for(int i = 1; i <= n; i++) {
        if(freq[i] == 1) {
            if(ini == 0) ini = i;
            else fim = i;
        }
    }

    freq[ini]--;
    queue<int> lista;
    lista.push(ini);
    int last;
    bool ok = 0;
    vis[ini] = 1;

    while(!lista.empty()) {
        int at = lista.front();
        lista.pop();
        cout << at << " ";
        for(auto z : v[at]) {
            if(!ok and freq[z] == 2 and !vis[z]) vis[z] = 1, lista.push(z);
            else if(ok and inter(last,at,z) and !vis[z]) vis[z] = 1, lista.push(z);
        }
        ok = 1;
        last = at;
    }
    cout << fim << endl;

    return 0;
}

