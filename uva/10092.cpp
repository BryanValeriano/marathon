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

const int T = 25;
const int N = 2000;

int source = 0;
int sink = N-1;

struct edg {
    int a,b,cap,flow;
};

int nk,np;
int d[N], ptr[N], q[N];
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
        int v= q[qh++];
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
    if(v == t) return flow;
    for(;ptr[v]<(int)g[v].size();++ptr[v]) {
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

void init() {
    e.clear();
    for(int i = 0; i < N; i++) g[i].clear();
}

void build() {
    for(int i = 1; i <= nk; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int id = g[i][j], to = e[id].b;
            if(e[id].flow == 1) cout << to-T << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nk >> np;
    while(nk or np) {
        init();
        int gol = 0;

        for(int i = 1; i <= nk; i++) {
            int x; cin >> x;
            add(source,i,x);
            gol += x;
        }

        for(int i = 1; i <= np; i++) {
            int qtd; cin >> qtd;
            add(T+i,sink,1);
            for(int j = 0; j < qtd; j++) {
                int x; cin >> x;
                add(x,T+i,1);
            }
        }
        int ok = dinic(source,sink) == gol;
        if(!ok) cout << 0 << endl;
        else {
            cout << 1 << endl;
            build();
        }
        cin >> nk >> np;
    }
    return 0;
}

