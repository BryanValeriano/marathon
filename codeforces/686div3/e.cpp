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
const int LOG = log2(T)+1;

int anc[LOG][T];
vector<int> g[T];
int pai[T], p[T], degree[T], niv[T];
ll peso[T];
ll ans;
int n;

ii lca(int u, int v) {
    if(niv[v] < niv[u]) swap(v,u);
    for(int i = LOG-1; i >= 0; i--)
        if(niv[v]-(1<<i) >= niv[u]) v = anc[i][v];

    if(u==v) return mk(u,u);

    for(int i = LOG-1; i >= 0; i--) {
        if(anc[i][u] != anc[i][v]) {
            u = anc[i][u];
            v = anc[i][v];
        }
    }

    return mk(u,v);
}

void dfs(int u) {
    peso[u] = 1;
    for(int v : g[u]) {
        if(peso[v]) continue;
        niv[v] = niv[u]+1;
        anc[0][v] = u;
        dfs(v);
        peso[u] += peso[v];
    }
    ans += peso[u]-1;
}

void build() {
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 1) {
            dfs(i);
            break;
        }
    }

    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
        }
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(p[x] < p[y]) swap(x,y);
    p[x] += p[y];
    pai[y] = x;
}

void pre() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        p[i] = 1;
        pai[i] = i;
        degree[i] = 0;
        peso[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        pre();
        int x = -1, y = -1;
        ans = 0;
        for(int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            if(find(a) == find(b)) x = a, y = b;
            else {
                join(a,b);
                g[a].pb(b);
                g[b].pb(a);
                degree[a]++;
                degree[b]++;
            }
        }

        build();
        int xx = x, yy = y;
        tie(x,y) = lca(x,y);
        cout << ans << " | ";

        if(x != y) {
            int k = anc[0][x];
            ans += (peso[k]-peso[x])*peso[x];
            ans += (peso[k]-peso[y])*peso[y];
            ans -= peso[x]*peso[y];
        } else {
            x = xx, y = yy;
            if(niv[x] > niv[y]) swap(x,y);
            ans += (n-peso[y])*(peso[y])+niv[y]-niv[x];
            //ans += (peso[x]-peso[y])*(peso[y]);
            //ans += (peso[x]*(peso[x]-1));
        }

        cout << ans << endl;
    }
    return 0;
}

