#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
int n, m, cor[N], vis[N];
vector<int> g[N];

bool dfs(int at, int c) {
	vis[at] = 1;
	cor[at] = c;

	bool f = true;
	for(auto next : g[at]) {
		if(!vis[next]) {
			f &= dfs(next, 1 - c);
		} else if(cor[next] == cor[at]) {
			return false;
		}
	}

	return f;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while(m--) {
		int u, v;	cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	bool ans = true;
	for(int u = 1; u <= n; u++)
		if(!vis[u])
			ans &= dfs(u, 0);

	cout << ans << endl;

	if(ans == 1) {
		for(int u = 1; u <= n; u++)
			cout << u << " " << cor[u] << endl;
	}

	return 0;
}
