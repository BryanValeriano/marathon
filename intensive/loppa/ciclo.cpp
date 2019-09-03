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
int vis[N];

// O(N + M)
bool dfs(int at) {
	vis[at] = 1;

	bool f = false;
	for(auto next : g[at]) {
		if(!vis[next])	
			f |= dfs(next);
		else if (vis[next] == 1) {
			return true;
		}
	}

	vis[at] = 2;

	return f;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	while(m--) {
		int u, v;	cin >> u >> v;
		g[u].pb(v);
	}

	bool ans = false;
	for(int i = 1; i <= n; i++) 
		if(!vis[i])
			if(dfs(i))
				ans = true;

	cout << ans << endl;

	return 0;
}
