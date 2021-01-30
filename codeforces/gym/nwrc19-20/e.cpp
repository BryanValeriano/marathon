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
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5+5;
vi g[T];
vi path;
int dist[T];

bool dfs(int u, int pai, int gol) {
    if(u==gol) return 1;
    for(int v : g[u]) {
        if(v==pai) continue;
        path.pb(v);
        if(dfs(v,u,gol)) return 1;
        path.pop_back();
    }
    return 0;
}

void bfs(int u) {
    dist[u] = 1;
    queue<int> fila;
    fila.push(u);
    while(!fila.empty()) {
        u = fila.front();
        fila.pop();
        for(int v : g[u]) {
            if(!dist[v]) {
                dist[v] = dist[u]+1;
                fila.push(v);
            }
        }
    }
}

int tent(int a, int b, int n, vi &v) {
    path.clear();
    path.pb(a);
    dfs(a,a,b);
    int k = path.size();
    if(!(k&1)) return 0;

    int mid = path[k>>1];
    for(int i = 1; i <= n; i++) dist[i] = 0;
    bfs(mid);
    bool ok = 1;
    for(int i = 1; i < v.size(); i++)
        ok &= dist[v[i]] == dist[v[i-1]];

    return (ok? mid : 0);
}

void dfs2(int u) {
    for(int v : g[u]) {
        if(dist[v]) continue;
        dist[v] = dist[u]+1;
        dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi v(m);
    for(int i = 0; i < m; i++) cin >> v[i];
    int a = v[0];
    int b = v[0];
    dist[a] = 1;
    dfs2(v[0]);

    int mx = 0;
    for(int i = 0; i < m; i++)
        if(dist[v[i]] > mx) b = v[i], mx = dist[v[i]];

    if(m==1) {
        cout << "YES\n";
        cout << v[0] << endl;
        return 0;
    }

    int mid = tent(a,b,n,v);
    if(mid) {
        cout << "YES\n";
        cout << mid << endl;
        return 0;
    }
    cout << "NO\n";
    return 0;
}

