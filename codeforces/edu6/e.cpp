#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 4e5 + 10;
int cor[T];
int tmp[T];
int tin[T];
int tout[T];
ll seg[4*T];
ll lazy[4*T];
vector<int> g[T];
int a,b,val;
int t = 0;

void dfs(int u) {
	tin[u] = ++t;
	cor[tin[u]] = tmp[u];

	for(auto v : g[u]) 
		if(!tin[v]) dfs(v);

	tout[u] = t;
}

void build(int node, int i, int j) {
	if(i == j) seg[node] |= (1LL << cor[i]);
	else {
		int mid = (i+j) >> 1;
		build(2*node, i, mid);
		build(2*node+1, mid+1, j);
		seg[node] = (seg[2*node] | seg[2*node+1]);
	}
}

void prop(int node, int i, int j) {
	if(!lazy[node]) return;
	seg[node] = 0;
	seg[node] |= (1LL << lazy[node]);
	if(i != j) {
		lazy[2*node] = lazy[node];
		lazy[2*node+1] = lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int i, int j) {
	prop(node,i,j);
	if(i > b or j < a) return;
	if(i >= a and j <= b) { 
		lazy[node] = val;
		prop(node,i,j);
	} else {
		int mid = (i+j) >> 1;
		update(2*node, i ,mid);
		update(2*node+1, mid+1, j);
		seg[node] = (seg[2*node] | seg[2*node+1]);
	}
}

ll query(int node, int i, int j) {
	prop(node,i,j);
	if(i > b or j < a) return 0;
	if(i >= a and j <= b) return seg[node];
	int mid = (i+j) >> 1;
	return (query(2*node, i, mid) | query(2*node+1, mid+1, j));
}

int main() {
    ios_base::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	int u,v,tipo;
	for(int i = 1; i <= n; i++) cin >> tmp[i], tmp[i];
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	build(1,1,n);
	while(q--) {
		cin >> tipo;
		if(tipo == 1) {
			cin >> u >> v;
			a = tin[u];
			b = tout[u];
			val = v;
			update(1,1,n);
		} else {
			cin >> u;
			a = tin[u];
			b = tout[u];
			ll x = query(1,1,n);
			cout << __builtin_popcountll(x) << endl;
		}
	}
    return 0;
}
