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
const int T = 2e5+4;

vii edges[2];
vii g[T];
ii ans[T];
int in[T], height[T];
bool ok[T], dag[T], vis[T];
int n,m,cont,cont2;

void build() {
	cont = cont2 = 0;
	edges[0].clear();
	edges[1].clear();
	for(int i = 0; i <= max(n,m); i++) {
		g[i].clear();
		ok[i] = dag[i] = vis[i] = 0;
		height[i] = INF;
	}
}

int next(int u, ii uv) {
	return (u == uv.fi? uv.se : uv.fi);
}

bool toposort() {
	for(int i = 0; i < edges[1].size(); i++) {
		int u = edges[1][i].fi;
		int v = edges[1][i].se;
		in[v]++;
		ok[u] = ok[v] = 1;
	}

	queue<int> fila;

	for(int i = 1; i <= n; i++) 
		if(ok[i] && (!in[i])) fila.push(i);

	while(!fila.empty()) {
		int u = fila.front();
		dag[u] = 1;
		height[u] = cont2++;
		fila.pop();
		for(auto [type, pos] : g[u]) {
			if(!type) continue;
			int v = edges[type][pos].se;
			in[v]--;
			ans[cont++] = mk(u,v);
			//cerr << u << " -> " << v << endl;
			if(!in[v]) fila.push(v);
		}
	}
	
	//cerr << " $$ " << cont << " " << edges[1].size() << " = " << (cont == edges[1].size()) << endl;
	return (cont == edges[1].size());
}

void solveUndirect() {
	queue<int> fila;
	for(int i = 1; i <= n; i++) if(dag[i]) fila.push(i);

	//2 cases = (dag | noDag) && (dag | dag)
	while(!fila.empty()) {
		int u = fila.front();
		fila.pop();
		for(auto [type,pos] : g[u]) {
			if(type || vis[pos]) continue;
			vis[pos] = 1;
			int v = next(u, edges[type][pos]);
			if(dag[v]) {
				if(height[u] < height[v]) ans[cont++] = mk(u,v);
				else ans[cont++] = mk(v,u);
			} else {
				ans[cont++] = mk(u,v);
				if(!dag[v]) {
					dag[v] = 1;
					fila.push(v);
					height[v] = cont2++;
				}
			}
		}
	}

	//last case = (noDag | noDag)
	for(int i = 1; i <= n; i++) if(!dag[i]) fila.push(i);

	while(!fila.empty()) {
		int u = fila.front();
		fila.pop();
		for(auto [type,pos] : g[u]) {
			if(type || vis[pos]) continue;
			vis[pos] = 1;
			int v = next(u, edges[type][pos]);
			if(dag[v]) continue;
			ans[cont++] = mk(v,u);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		cin >> n >> m;
		build();
		for(int i = 0; i < m; i++) {
			int t,u,v; cin >> t >> u >> v;
			g[u].eb(t,edges[t].size());
			if(!t) g[v].eb(t,edges[t].size());
			edges[t].eb(u,v);
		}
		if(toposort()) {
			cout << "YES" << endl;
			solveUndirect();
			for(int i = 0; i < m; i++) cout << ans[i].fi << " " << ans[i].se << endl;
		} else cout << "NO" << endl;

	}
    return 0;
}

