#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl '\n'

typedef pair<int,int> ii;

const int T = 505;
int v[T];
int vis[T];
int in[T];
int tmp[T];
vector<int> g[T];
vector<int> gg[T];
vector<int> first;
int gol;
int n;
int vez;

void init() {
    for(int i = 1; i < T; i++) g[i].clear();
    for(int i = 1; i < T; i++) gg[i].clear();
    first.clear();
    memset(in, 0, sizeof in);
}

int dfs2(int u) {
    vis[u] = vez;
    int ans = v[u];
    for(auto x : gg[u]) 
        if(vis[x] != vez) ans += dfs2(x);
    return ans;
}

int dfs(int u) {
    vis[u] = vez;
    int ans = v[u];
    for(auto x : g[u]) { 
        tmp[x]++;
        if(vis[x] != vez and tmp[x] == in[x] and x != gol) ans += dfs(x);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m,q,x,y;
    cin >> n >> m;
    int cont = 0;
    while(n or m) {
        init();
        for(int i = 1; i <= n; i++) cin >> v[i];
        for(int i = 0; i < m; i++) {
            cin >> x >> y; 
            in[y]++;
            g[x].pb(y);
            gg[y].pb(x);
        }
        cin >> q;
        cout << "Case #" << ++cont << ":" << endl;
        for(int i = 1; i <= n; i++) if(!in[i]) first.pb(i);
        while(q--) {
            vez++;
            cin >> gol;
            memset(tmp, 0, sizeof tmp);

            int maxi = 0;
            for(auto x : first) if(vis[x] != vez and x != gol) maxi += dfs(x);

            vez++;
            int mini = dfs2(gol) - v[gol];
            cout << maxi - mini << endl;
        }
        cin >> n >> m;
        cout << endl;
    }
    return 0;
}

