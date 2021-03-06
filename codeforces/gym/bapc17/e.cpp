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
const double eps = 1e-7;
const int N = 2e5 + 5;
const int S = N-2, T = N-1;

struct edge {
	int a, b, cap, flow;
};

int d[N], ptr[N], q[N];
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

const int Z = 255;
int n,b,r;
ll bx[Z], by[Z], rx[Z], ry[Z];
double di[Z][Z];

bool check(double dist) {
    e.clear();
    for(int i = 0; i < N; i++) g[i].clear();
    for(int i = 0; i < b; i++) add_edge(S,i,1);
    for(int i = 0; i < r; i++) add_edge(i+Z,T,1);

    for(int i = 0; i < b; i++)
        for(int j = 0; j < r; j++) {
            if(di[i][j] < dist+eps) {
                add_edge(i,j+Z,1);
            }
        }

    int mvc = dinic(S,T);
    return(b+r-mvc >= n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> b >> r;
    for(int i = 0; i < b; i++) cin >> bx[i] >> by[i];
    for(int i = 0; i < r; i++) cin >> rx[i] >> ry[i];

    for(int i = 0; i < b; i++)
        for(int j = 0; j < r; j++){
            di[i][j] = hypot(abs(bx[i]-rx[j]),abs(by[i]-ry[j]));
            //cout << i <<" " << j << " = " << di[i][j] << endl;
        }

    double l = 0;
    double r = 1e9;

    for(int i = 0; i < 60; i++) {
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(6) << l << endl;
    return 0;
}

