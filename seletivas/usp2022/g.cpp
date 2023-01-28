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
const int LOG = 19;
int n,m,t;
vii g[T];
vii gCompress[T];
multiset<int> pontes;
int d[T], low[T], pai[T], nivel[T];
int ancestral[T][LOG+2];
int peso[T][LOG];

void buildDSU() {
	for(int i = 0; i < T; i++) pai[i] = i;
}

int find(int x) {
	return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(g[v].size() > g[u].size()) swap(u,v);
	pai[v] = pai[u];
	for(auto [nv, w] : gCompress[v]) 
		if(find(nv) != find(u)) gCompress[u].eb(find(nv),w);
}

void dfs(int u, int p) {
	d[u] = low[u] = ++t;
	for(auto [v,w] : g[u]) {
		if(!d[v] && v != p) {
			dfs(v,u);
			if(low[v] > d[u]) {
				pontes.insert(w);
				gCompress[find(u)].eb(find(v),w);
				gCompress[find(v)].eb(find(u),w);
			} else join(u,v);
			low[u] = min(low[v], low[u]);
		} else if(v != p) low[u] = min(low[u], d[v]);
	}
}

void compress() { dfs(1,1); }

void dfsLca(int u, int p) {
	for(auto [v,w] : gCompress[u]) {
		v = find(v);
		if(v == p) continue;
		ancestral[v][0] = u;
		peso[v][0] = w;
		nivel[v] = nivel[u]+1;
		dfsLca(v,u);
	}
}

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG; i >= 0; i--)
        if(nivel[u] - (1<<i) >= nivel[v]) 
            u = ancestral[u][i];
		
    if(u == v) return u;
    
    for(int i = LOG; i >= 0; i--) 
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

void buildLca() {
	memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);

	ancestral[find(1)][0] = find(1);
	nivel[find(1)] = 0;

	dfsLca(find(1), find(1));

	for(int j = 1; j < LOG; j++)
		for(int i = 1; i <= n; i++) {
			if(ancestral[i][j-1] == -1) continue;
			ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}
}

void sobeMergeando(int u, int l) {
	if(find(u) == find(l)) return;

	for(int i = LOG; i >= 0; i--) 	
		if(find(u) == find(ancestral[u][i]))
				u = ancestral[u][i];

	join(find(u), find(ancestral[u][0]));
	pontes.erase(pontes.find(peso[u][0]));

	sobeMergeando(ancestral[u][0], l);
}

void mergeComponents(int u, int v) {
	u = find(u); v = find(v);
	int l = lca(u,v);
	sobeMergeando(find(u), find(l));
	sobeMergeando(find(v), find(l));
}

int main() {
    ios_base::sync_with_stdio(false);
	buildDSU();
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u,v,w; cin >> u >> v >> w;
		g[u].eb(v,w);
		g[v].eb(u,w);
	}
	compress();
	buildLca();
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		int u,v,w; cin >> u >> v >> w;
		mergeComponents(u,v);
		if(pontes.size()) {
			int x = *pontes.begin();
			cout << x << endl;
		}
		else cout << -1 << endl;
	}
    return 0;
}
