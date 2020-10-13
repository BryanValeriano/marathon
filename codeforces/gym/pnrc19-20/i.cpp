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
const int N = 5e5 + 5;
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

const int Z = 505;
bool col[Z], vis[Z];
vector<int> h[Z];
map<string,int> bag;
vector<string> v;
int cont;

void bip(int u, bool ok) {
    vis[u] = 1;
    col[u] = ok;
    for(int v : h[u])
        if(!vis[v])
            bip(v,!ok);
}

int id(string s) {
    if(!bag.count(s)) bag[s] = ++cont;
    return bag[s];
}

int hamming(string s, string t) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        ans += (s[i] != t[i]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        v.pb(s);
        id(s);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(hamming(v[i],v[j])==2) {
                h[id(v[i])].pb(id(v[j]));
                h[id(v[j])].pb(id(v[i]));
            }

    for(int i = 0; i < n; i++) {
        if(!vis[id(v[i])]) bip(id(v[i]),0);
        if(col[id(v[i])]) add_edge(S,id(v[i]),1);
        else add_edge(id(v[i]),T,1);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(hamming(v[i],v[j])==2) {
                if(col[id(v[i])]) add_edge(id(v[i]),id(v[j]),1);
                else add_edge(id(v[j]),id(v[i]),1);
            }


    cout << n-dinic(S,T) << endl;
    return 0;
}

