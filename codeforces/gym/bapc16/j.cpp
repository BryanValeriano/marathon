#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 4e4 + 5;
const int S = N-2, T = N-1;
const int OFF = 110;

struct edge {
	int a, b, cap, flow;
};

int d[N], ptr[N], q[N], x[N], y[N];
vector<edge> e;
vector<int> g[N];

void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs(int s, int t) {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow, int t) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow), t);
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic(int s, int t) {
	int flow = 0;
	for (;;) {
		if (!bfs(s, t))  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (s, INF, t))
			flow += pushed;
	}
	return flow;
}

int dist(int a, int b) {
    return abs(x[a]-x[b]) + abs(y[a]-y[b]);
}

bool check(int mid, int n) {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        g[i+OFF].clear();
    }
    g[S].clear();
    e.clear();

    for(int i = 1; i <= n; i++) {
        add_edge(S,i,1);
        add_edge(i+OFF,T,1);
        for(int j = 1; j <= n; j++)
            if(dist(i,j+OFF) <= mid) add_edge(i,j+OFF,i);
    }

    return (dinic(S,T)==n);
}

int main (void) {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++) cin >> x[i+OFF] >> y[i+OFF];

    int l = 0;
    int r = 1e9;
    int ans = r;

    while(l<=r) {
        int mid = (l+r)>>1;
        if(check(mid,n)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans << endl;

	return 0;
}
