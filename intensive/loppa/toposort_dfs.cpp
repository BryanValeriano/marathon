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
stack<int> s;
bool vis[N];

void dfs(int at) {
	vis[at] = true;

	for(auto next : g[at]) 
		if(!vis[next])
			dfs(next);

	s.push(at);
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	while(m--) {
		int u, v;	cin >> u >> v;
		g[u].pb(v);
	}

	for(int u = 1; u <= n; u++) 
		if(!vis[u])
			dfs(u);

	vector<int> topo;
	while(!s.empty()) {
		topo.pb(s.top());
		s.pop();
	}

	for(auto vert : topo)
		cout << vert << " ";
	cout << endl;

	return 0;
}
