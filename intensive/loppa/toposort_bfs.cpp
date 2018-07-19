// http://br.spoj.com/problems/DUENDE/

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
int n, m, pai[N];
vector<int> g[N], topo;

void bfs() {
	queue<int> q;

	for(int i = 1; i <= n; i++) 
		if(!pai[i])
			q.push(i);

	while(!q.empty()) {
		int at = q.front();
		topo.pb(at);
		q.pop();

		for(auto next : g[at]) {
			pai[next]--;
			if(pai[next] == 0)
				q.push(next);
		}
	}

	for(auto vert : topo)
		cout << vert << " ";
	cout << endl;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	while(m--) {
		int u, v;	cin >> u >> v;
		g[u].pb(v);
		pai[v]++;
	}

	bfs();

	return 0;
}
