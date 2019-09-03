#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const int T = 550;
int n;
int u, v;
int id[T];
int pos[T];
vii g[T];
ll vis[T];
ll vez = 0;

int dfs(int atual) {
    //cout << "DBG: " << atual << " " << id[atual] << endl;
    vis[atual] = vez;
    int mini = INF;
    if(atual != u) mini = id[atual];
    for(auto filho : g[atual])
        if(vis[filho.fi] != vez and filho.se == 1) 
            mini = min(mini, dfs(filho.fi));
    return mini;
}

int main() {
    ios::sync_with_stdio(false);
    int m, q;
    while(cin >> n) {
        cin >> m >> q;
        char oper;
        for(int i = 1; i <= n; i++) { 
            cin >> u;
            id[i] = u;
            pos[i] = i;
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            g[v].eb(u,1);
            g[u].eb(v,0);
        }
        for(int i = 0; i < q; i++) {
            cin >> oper;
            if(oper == 'T') {
                cin >> u >> v;
                swap(id[pos[u]], id[pos[v]]);
                swap(pos[u], pos[v]);
            }
            if(oper == 'P') {
                cin >> u;
                u = pos[u];
                vez++;
                int ans = dfs(u);
                if(ans == INF) cout << '*';
                else cout << ans;
                cout << endl;
            }
        }
        for(int i = 1; i <= n; i++) g[i].clear();
    }

    return 0;
}

