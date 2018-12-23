#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, int> li;
typedef vector< pair<int,int> > vii;
const ll INF = LLONG_MAX;
const int T = 1e5 + 10;
const int LOG = 22;
int n, q;
vector<ii> g[T];
int nivel[T];
int pai[T];
int ancestral[T][LOG];
ll peso[T];
int x1,x2,p;

int fat[T];
int alt[T];

ll dist[2][T];

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--)
        if(u - (1<<i) >= nivel[v]) u = ancestral[u][i];

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--) 
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return pai[u];
}

void query() {
    int u,v;
    while(q--) {
        cin >> u >> v;
        cout << min( { peso[u] + peso[v] - 2*peso[lca(u,v)], dist[0][u] + dist[0][v], dist[1][u] + dist[1][v] } ) << endl;
        //cout << "1: " << peso[u] + peso[v] - 2*peso[lca(u,v)] << endl;
        //cout << "2: " << dist[0][u] + dist[0][v] << endl;
        //cout << "3: " << dist[1][u] + dist[1][v] << endl;
    }
}

void dijkstra(int ori, ll dist[]) {
    for(int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue< li, vector<li>, greater<li> >pq;
    dist[ori] = 0;
    pq.emplace(0,ori);
    while(!pq.empty()) {
        li davez = pq.top();
        pq.pop();
        int atual = davez.se;
        for(int i = 0; i < g[atual].size(); i++) {
            int viz = g[atual][i].fi;
            int d = g[atual][i].se;
            if(dist[viz] > dist[atual] + d) { 
                dist[viz] = dist[atual] + d;
                pq.emplace(dist[viz], viz);
            }
        }
    }
}

int find(int x) {
    return (fat[x] == x? x : fat[x] = find(fat[x]));
}

void join(int x, int y) {
    x = find(x); y = find(y);
    if(alt[x] < alt[y]) swap(x,y);
    fat[y] = x;
    if(alt[x] == alt[y]) alt[x]++;
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

void buildLca() {
    memset(nivel, -1, sizeof nivel);
    nivel[1] = 0;
    pai[1] = 1;
    peso[1] = 0;
    dfs(1);
    
    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];

    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    int u, v, w;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        fat[i] = i;
        alt[i] = 0;
        peso[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        if(find(u) != find(v)) {
            join(u,v);
            g[u].eb(v,w);
            g[v].eb(u,w);
        } else { x1 = u; x2 = v; p = w; }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        read(); 
        buildLca();
        g[x1].eb(x2,p);
        g[x2].eb(x1,p);
        dijkstra(x1,dist[0]);
        dijkstra(x2,dist[1]);
        query();
    }    
    return 0;
}

