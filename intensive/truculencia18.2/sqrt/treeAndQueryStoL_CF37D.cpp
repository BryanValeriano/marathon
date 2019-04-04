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
const int T = 1e5 + 10;
vector<int> g[T];
map<int,int> track[T];
map<int,int> resp[T];
int peso[T];
int ans[T];
int cor[T];
bool vis[T];
vii querys[T];

void dfs(int u) {
    vis[u] = true;
    track[u][cor[u]]++;
    resp[u][track[u][cor[u]]]++;
    peso[u]++;

    for(int v : g[u]) {
        if(!vis[v]) {
            dfs(v);
            if(peso[u] < peso[v]) {
                swap(track[u], track[v]);
                swap(resp[u], resp[v]);
            }
            for(auto x : track[v]) {
                int ini = track[u][x.fi];
                for(int i = ini+1; i <= ini + x.se; i++)
                    resp[u][i]++;
                track[u][x.fi] += x.se;
            }
            peso[u] += peso[v];
        }
    }

    for(auto x : querys[u]) 
        ans[x.fi] = resp[u][x.se];
}

int main() {
    ios::sync_with_stdio(false);
    int n, q, u, v;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> cor[i];
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 0; i < q; i++) {
        cin >> u >> v;
        querys[u].eb(i,v);
    }
    dfs(1);
    for(int i = 0; i < q; i++) cout << ans[i] << endl;
    return 0;
}

