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
int n, m, dist[N];
vector<int> g[N];

// O(N + M)
void bfs(int beg) {
	memset(dist, INF, sizeof dist);
	queue<int> q;

	q.push(beg);
	dist[beg] = 0;

	while(!q.empty()) {
		int at = q.front();
		q.pop();

		for(int i = 0; i < (int)g[at].size(); i++) {
			int next = g[at][i];
			if(dist[next] == INF) {
				dist[next] = dist[at] + 1;
				q.push(next);
			}
		}
	}

	for(int i = 1; i <= n; i++)
		cout << i << " " << dist[i] << endl;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	while(m--) {
		int u, v;	cin >> u >> v;
		g[u].pb(v);
	}

	bfs(1);

	return 0;
}
