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
const int T = 2e5+5;

vii e;
int dist[T];
bool vis[T];
vector<int> g[T];
vector<int> ans[T];
queue<int> fila;

int bfs() {
    int mx = 1;
    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        for(int ee : g[u]) {
            if(vis[ee]) continue;
            auto [x,y] = e[ee];
            int v = (x==u?y:x);
            vis[ee] = 1;

            if(!dist[v]) {
                dist[v] = dist[u]+1;
                mx = max(dist[v],mx);
                ans[dist[v]].pb(v);
                fila.push(v);
            }
            else if(dist[v] != dist[u]+1) return 0;
        }
    }
    if(ans[mx].size() > 1) return 0;
    return ans[mx].back();
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;

    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(e.size());
        g[b].pb(e.size());
        e.eb(a,b);
    }

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        dist[x] = 1;
        ans[1].pb(x);
        fila.push(x);
    }

    int ok = bfs();
    if(ok) {
        cout << "YES\n";
        cout << ok << endl;
        return 0;
    } cout << "NO\n";
    return 0;
}

