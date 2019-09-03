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
int n, m;
vector<int> g[N];
bool vis[N];

// O(N + M)
void dfs(int at) {
	vis[at] = true;

	for(auto next : g[at]) 		//for(int i = 0; i < (int)g[at].size(); i++)
		if(!vis[next])			//	int next = g[at][i];
			dfs(next);
}

int main (void) {
	ios_base::sync_with_stdio(false);

	while(cin >> n >> m, n) {
		for(int i = 0; i < N; i++)
			g[i].clear();

		while(m--) {
			int u, v, p;	cin >> u >> v >> p;
			if(p==1) {
				g[u].pb(v);
			} else {
				g[u].pb(v);
				g[v].pb(u);
			}
		}

		int ans = 1;
		for(int u = 1; u <= n; u++) {
			memset(vis, 0, sizeof vis);
			dfs(u);

			for(int v = 1; v <= n; v++)
				if(!vis[v])
					ans = 0;
		}

		cout << ans << endl;
	}

	return 0;
}
