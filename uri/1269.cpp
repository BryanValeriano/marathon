#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 1e3 + 3;

int n,e, vez;
ll cost[T];
ll ans[T];
int in[T];
int vis[T];
set<int> bag[T];
set<int> anc[T];
vector<int> g[T];

void reset(int n, int e) {
    for(int i = 0; i <= n; i++) {
        bag[i].clear();
        g[i].clear();
        anc[i].clear();
    }
    for(int i = 0; i <= e; i++) ans[i] = 0;
    vez++;
}

void dfs(int at) {
    if(vis[at] == vez) return;
    vis[at] = vez;
    for(int v : g[at]) {
        dfs(v);
        cost[at] += cost[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> e;
    int m,k,v;
    while(n or e) {
        reset(n,e);
        for(int i = 1; i <= n; i++) {
            cin >> cost[i] >> m >> k;
            for(int j = 0; j < m; j++) cin >> v, g[i].pb(v), in[v]++;
            for(int j = 0; j < k; j++) cin >> v, bag[i].insert(v);
        }

        for(int i = 1; i <= n; i++) dfs(i);
        queue<int> lista;
        for(int i = 1; i <= n; i++) if(!in[i]) lista.push(i);

        while(!lista.empty()) {
            int at = lista.front();
            lista.pop();

            for(auto ok : bag[at]) {
                if(!anc[at].count(ok)) {
                    ans[ok] += cost[at];
                    anc[at].insert(ok);
                }
            }

            for(int v : g[at]) {
                in[v]--;
                for(auto ok : anc[at]) anc[v].insert(ok);
                if(!in[v]) lista.push(v);
            }
        }

        cout << "*****" << endl;
        for(int i = 1; i <= e; i++) cout << i << " " << ans[i] << endl;
        cin >> n >> e;
    }
    return 0;
}

