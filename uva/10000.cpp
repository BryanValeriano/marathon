#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 102;
vector<int> g[T];
int best[T], in[T];

void dfs(int u) {
    for(int v : g[u]) {
        in[v]++;
        if(in[v] == 1)
            dfs(v);
    }
}

ii topoSort(int s) {
    queue<int> fila;
    fila.push(s);
    ii ans = mk(0,s);
    dfs(s);
    best[s] = 0;

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        if(best[u] > ans.fi) ans = mk(best[u],u);
        else if(best[u] == ans.fi) ans.se = min(ans.se,u);
        for(int v : g[u]) {
            in[v]--;
            best[v] = max(best[v],best[u]+1);
            if(!in[v]) fila.push(v);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,s;
    cin >> n;
    int cont = 0;

    while(n) {
        for(int i = 1; i <= n; i++) {
            g[i].clear();
            best[i] = in[i] = 0;
        }

        cin >> s;
        int u,v;
        cin >> u >> v;

        while(u or v) {
            g[u].pb(v);
            cin >> u >> v;
        }

        ii ans = topoSort(s);

        cout << "Case " << ++cont << ": The longest path from " << s << " has length " << ans.fi << ", finishing at " << ans.se << ".\n\n";
        cin >> n;
    }
    return 0;
}

