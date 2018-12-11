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
const int T = 1e5 +30;
const int LOG = 20;
int n;
int a[T];
int b[T];
int nivel[T];
int pai[T];
int peso[T];
bool vis[T];
int ancestral[T][LOG];
vector<int> g[T];

int lower(int u, int v) {
    if(nivel[u] > nivel[v]) return u;
    return v;
}

void print() {
    for(int i = 0; i < n-1; i++)
        cout << peso[lower(a[i],b[i])] << " ";
    cout << endl;
}

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--)
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

void dfs(int u, bool flag) {
    if(flag) vis[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(nivel[v] == -1) {
            nivel[v] = nivel[u] + 1;
            pai[v] = u;
            dfs(v,flag);
        }
        if(!vis[v] and flag) {
            dfs(v,flag);
            peso[u] += peso[v];
        }
    }
}

void road() {
    int k; cin >> k;
    int u, v;
    for(int i = 0; i < k; i++) {
        cin >> u >> v;
        int anc = lca(u,v);
        peso[u]++; peso[v]++;
        peso[anc]-=2;
    }
    dfs(1, true);
}

void build() {
    memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);
    nivel[1] = 0;
    pai[1] = 1;
    dfs(1, false);
    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a[i] >> b[i];
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    read();
    build();
    road();
    print();
    return 0;
}

