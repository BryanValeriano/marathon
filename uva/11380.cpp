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

const int N = 2e3 + 100;
const int GHST = 1E3;
const int S = N-2;
const int T = N-1;

struct edge {
    int a, b, cap, flow;
};

int d[N], ptr[N], q[N];
vector<edge> e;
vector<int> g[N];

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
            int id = g[v][i],
                to = e[g[v][i]].b;
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

int n,m,z, tot;

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

int id(int x, int y) {
    return 30*x + y;
}

void init() {
    e.clear();
    for(int i = 0; i < N; i++) g[i].clear();
}

void read() {
    char c;
    tot = 0;
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < m; j++) {
            cin >> c;
            if(c == '*' or c == '.') {
                if(c == '*') tot++, add(S,id(i,j), 1);

                add(id(i,j), id(i,j) + GHST, 1);
                for(int k = 0; k < 4; k++) {
                    int ii = i + mov[k][0];
                    int jj = j + mov[k][1];
                    if(isIn(ii,jj)) add(id(i,j) + GHST, id(ii,jj), 1);
                }
            } 

            else if(c == '@' or c == '#') {
                for(int k = 0; k < 4; k++) {
                    int ii = i + mov[k][0];
                    int jj = j + mov[k][1];
                    if(isIn(ii,jj)) add(id(i,j), id(ii,jj), INF);
                }
                if(c == '#') add(id(i,j), T, z);
            } 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    while(cin >> n) {
        cin >> m >> z;
        init();
        read();
        cout << dinic(S,T) << endl;
    }

    return 0;
}

