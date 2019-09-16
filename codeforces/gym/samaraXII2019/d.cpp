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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 3;
const int LOG = log2(T) + 2;

int pai[T];
int nivel[T];
bool vis[T];
int ancestral[T][LOG+1];
vector<int> g[T], r, b;
int n, q, rj, bj;

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG; i >= 0; i--)
        if(nivel[u] - (1 << i) >= nivel[v])
            u = ancestral[u][i];

    if(u == v) return u;

    for(int i = LOG; i >= 0; i--) {
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }

    return ancestral[u][0];
}

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u])
        if(!vis[v]) {
            nivel[v] = nivel[u] + 1;
            pai[v] = u;
            dfs(v);
        }
}

void build() {
    memset(pai, -1, sizeof pai);
    memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);
    pai[1] = 1;
    nivel[1] = 0;
    dfs(1);

    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
}

string corner(int x, int y, int anc) {
    if(anc == y) {
        swap(x,y);
        swap(rj,bj);
        swap(r,b);
    }


    for(int i = 0; i < rj; i++)
        if(lca(y,r[i]) == y) return "NO";

    return "YES";
}


void solve() {
    int x,y;
    cin >> q;
    while(q--) {
        cin >> rj >> bj;
        r.clear();
        b.clear();

        for(int i = 0; i < rj; i++) {
            cin >> x;
            r.pb(x);
        }
        for(int i = 0; i < bj; i++) {
            cin >> x;
            b.pb(x);
        }

        x = *r.begin();
        for(int i = 1; i < rj; i++) x = lca(x,r[i]);
        y = *b.begin();
        for(int i = 1; i < bj; i++) y = lca(y,b[i]);

        int anc = lca(x, y);

        if(x == y) cout << "NO" << endl;
        else if(anc != x and anc != y) cout << "YES" << endl;
        else cout << corner(x,y,anc) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    build();
    solve();
    return 0;
}

