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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1011;
const int N = 505;
const int S = 0;
const int F = T-1;

struct edge { int a, b, cap, flow; };

int d[T], ptr[T], q[T];
vector<edge> e;
vector<int> g[T];
int n,m;

void add(int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].pb(e.size());
    e.pb(e1);
    g[b].pb(e.size());
    e.pb(e2);
}

bool bfs(int s, int t) {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, sizeof d);
    d[s] = 0;
    while(qh < qt and d[t] == -1) {
        int v = q[qh++];
        for(size_t i = 0; i < g[v].size(); ++i) {
            int id = g[v][i], to = e[id].b;
            if(d[to] == -1 and e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] +1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow, int t) {
    if(!flow) return 0;
    if(v == t) return flow;
    for(; ptr[v] < g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]], to = e[id].b;
        if(d[to] != d[v] + 1) continue;
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow), t);
        if(pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic(int s, int t) {
    int flow = 0;
    for(;;) {
        if(!bfs(s,t)) break;
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s, INF, t)) flow += pushed;
    }
    return flow;
}

void build() {
    cin >> n >> m;
    e.clear();
    int ok;

    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i <= m; i++) g[i+N].clear();
    g[S].clear();
    g[F].clear();

    for(int i = 1; i <= n; i++) add(S,i,1);
    for(int i = 1; i <= m; i++) add(i+N,F,1);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> ok;
            if(ok) add(i,j+N,1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        build();
        cout << "Case " << ++cont << ": a maximum of " << dinic(S,F) << " nuts and bolts can be fitted together" << endl;
    }
    return 0;
}

