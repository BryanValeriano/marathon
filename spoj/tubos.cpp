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
const int T = 1e3+5;
vector<int> g[T];
int comp[T], low[T], d[T];
int t;
bool ans;

void dfs(int u, int pai) {
    d[u] = low[u] = ++t;

    for(int v : g[u]) {
        if(v == pai) continue;
        if(!low[v]) {
            dfs(v,u);
            if(low[v] > d[u]) ans = 0;
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u],d[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    while(n or m) {
        for(int i = 1; i <= n; i++) {
            low[i] = d[i] = 0;
            g[i].clear();
        }

        t = 0;
        ans = 1;

        while(m--) {
            int x,y; cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        ans = 1;
        dfs(1,1);

        cout << (ans? "S\n" : "N\n");

        cin >> n >> m;
    }
    return 0;
}

