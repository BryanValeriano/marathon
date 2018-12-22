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
const int T = 1e4 + 10;
const int LOG = 16;
vector<ii> g[T];
int n;
int first;
int pai[T];
int nivel[T];
int ancestral[T][LOG];
ll peso[T];

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--) 
        if(nivel[u] - (1<<i) >= nivel[v]) u = ancestral[u][i];

    if(u == v) return u;
    
    for(int i = LOG-1; i >= 0; i--) 
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return pai[u];
}

int sob(int u, int k) {
    k = nivel[u] - k;

    for(int i = LOG -1; i >= 0; i--)
        if(nivel[u] - (1<<i) >= k) u = ancestral[u][i];

    return u;
}

int search(int u, int v, int k) {
    int anc = lca(u,v);
    if(nivel[u] - k >= nivel[anc])
        return sob(u,k);
    else return sob(v, (nivel[v] - nivel[anc]) - (k - (nivel[u] - nivel[anc])));
}

void query() {
    string oper;
    int a,b,k;
    cin >> oper;
    while(oper != "DONE") {
        if(oper == "DIST") {
            cin >> a >> b; 
            cout << peso[a] + peso[b] - 2*peso[lca(a,b)] << endl;
        } else {
            cin >> a >> b >> k;
            cout << search(a,b,k-1) << endl;
        }
        cin >> oper;
    }
}

void dfs(int atual) {
    for(int i = 0; i < g[atual].size(); i++) {
        int viz = g[atual][i].fi;
        if(nivel[viz] == -1) {
            pai[viz] = atual;
            nivel[viz] = nivel[atual] + 1;
            peso[viz] = peso[atual] + g[atual][i].se;
            dfs(viz);
        }
    }
}

void build() {
    memset(nivel, -1, sizeof nivel);
    peso[first] = 0;
    pai[first] = first;
    nivel[first] = 0;
    dfs(first);

    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];

    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    int u,v,w;
    //memset(pai, -1, sizeof pai);
    //memset(nivel, -1, sizeof nivel);
    //memset(ancestral, -1, sizeof ancestral);
    //memset(peso, 0, sizeof peso);
    for(int i = 1; i <= n; i++)
        g[i].clear();

    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        if(i == 0) first = u;
        g[u].eb(v,w);
        g[v].eb(u,w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        read();
        build();
        query();
    }
    return 0;
}

