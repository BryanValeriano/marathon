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
const int N = 1e3 + 4;
bool erase[N];
vii g[N];

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.se > b.se;
}

int main() {
    ios::sync_with_stdio(false);
    int n; int m;
    cin >> n >> m;
    int aux;
    vii track;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        g[i].eb(i, aux);
        track.eb(i, aux);
    }
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].eb(v, g[v][0].se);
        g[v].eb(u, g[u][0].se);
    }
    sort(track.begin(), track.end(), cmp);
    ll resp = 0;
    for(int i = 0; i < n; i++) {
        int atual = track[i].fi;
        for(int j = 1; j < g[atual].size(); j++) 
            if(!erase[g[atual][j].fi]) 
                resp += g[atual][j].se;
        erase[atual] = true;
    }
    cout << resp << endl;
    return 0;
}

