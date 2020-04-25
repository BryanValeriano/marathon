#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 102;
const int T2 = 204;
const int N = T2*T2+100;
struct edg { int a,b,cap,flow; };

int source = N-2;
int sink = N-1;
vii cranes;
vector<int> builds;

int d[N], ptr[N], q[N];
int pai[N];
vector<edg> e;
vector<int> g[N];

void add(int a, int b, int cap) {
    edg e1 = {a,b,cap,0};
    edg e2 = {b,a,0,0};
    g[a].pb(e.size());
    e.pb(e1);
    g[b].pb(e.size());
    e.pb(e2);
}

bool bfs(int s, int t) {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d,-1,sizeof d);
    d[s] = 0;
    while(qh < qt and d[t] == -1) {
        int v = q[qh++];
        for(int i = 0; i < g[v].size(); ++i) {
            int id = g[v][i], to = e[id].b;
            if(d[to] == -1 and e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v]+1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow, int t) {
    if(!flow) return 0;
    if(v==t) return flow;
    for(; ptr[v] < g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]], to = e[id].b;
        if(d[to] != d[v]+1) continue;
        int pushed = dfs(to,min(flow,e[id].cap-e[id].flow),t);
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
    while(bfs(s,t)) {
        memset(ptr,0,sizeof ptr);
        while(int pushed = dfs(s,INF,t)) flow += pushed;
    }
    return flow;
}

void build() {
    memset(pai,-1,sizeof pai);
    for(int i = 0; i < cranes.size(); i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int id = g[i][j], to = e[id].b;
            if(e[id].flow == 1) pai[to] = i;
        }
        for(int j = 0; j < g[i+T].size(); j++) {
            int id = g[i+T][j], to = e[id].b;
            if(e[id].flow == 1) pai[to] = i+T;
        }
    }
    for(int i = 0; i < builds.size(); i++) {
        int node = i+T2;
        vector<int> ans;
        node = pai[node];
        while(~node) {
            if(node < T) ans.pb(node+1);
            node = pai[node];
        }
        reverse(ans.begin(),ans.end());
        for(auto x : ans) cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int w,l; cin >> w >> l;
        cranes.eb(w,l);
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        builds.pb(x);
        add(i+T2,sink,1);
    }

    for(int i = 0; i < n; i++) {
        if(cranes[i].fi == 0) add(source,i,1);
        add(i,i+T,1);

        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(cranes[i].se >= cranes[j].fi)
                add(i+T,j,1);
        }

        for(int j = 0; j < m; j++)
            if(cranes[i].se >= builds[j])
                add(i+T,j+T2,1);
    }


    int f = dinic(source,sink);
    if(f == m) build();
    else cout << "impossible" << endl;

    return 0;
}

