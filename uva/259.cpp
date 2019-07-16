#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int N = 51; 
const int T = 50;
const int S = 49;

struct edge {
    int a,b,cap,flow;
};

int d[N], ptr[N], q[N];
vector<edge> e;
vector<int> g[N];

void add(int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].pb((int)e.size());
    e.pb(e1);
    g[b].pb((int)e.size());
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
            int id = g[v][i],
                to = e[id].b;
            if(d[to] == -1 and e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow, int t) {
    if(!flow) return 0;
    if(v == t) return flow;
    for(; ptr[v] < g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
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
    while(bfs(s,t)) {
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s,INF,t)) flow += pushed;
    }
    return flow;
}

bool vis[N];
char ans[10];

void minCut(int at, int s) {
    vis[at] = 1;
    if(at <= 9) return;

    for(int i = 0; i < g[at].size(); i++) {
        edge edg = e[g[at][i]];
        int next = edg.b;
        if(edg.flow == 1 and next != s and at != s and next <= 9 and next != T) {
            ans[next] = at - 20 + 'A';
        } else if(!vis[next]) minCut(next,s);
    }
}

void init() {
    for(int i = 0; i < N; i++) g[i].clear();
    e.clear();
    memset(vis,0,sizeof vis);
    for(int i = 0; i < 10; i++) {
        ans[i] = '_';
        add(i,T,1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    string tmp;
    int tot = 0;
    init();

    while(getline(cin, tmp)) {
        if(tmp == "") {
            if(dinic(S,T) == tot) {
                minCut(S, S);
                cout << ans << endl;
            } else cout << "!" << endl;
            init();
            tot = 0;
        } else {
            int ini = tmp[0] - 'A' + 20;
            int qtd = tmp[1] - '0';
            tot += qtd;
            int x;
            add(S,ini,qtd);
            for(int i = 3; i < tmp.size()-1; i++) {
                x = tmp[i] - '0';
                add(ini,x,1);
            }
        }
    }

    if(dinic(S, T) == tot) {
        minCut(S, S);
        cout << ans << endl;
    } else cout << "!" << endl;

    return 0;
}

