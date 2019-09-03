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

const int T = 53;

struct edge {
    int to, cap, flow, rid;

    edge(int to, int cap, int flow, int rid) :
        to(to), cap(cap), flow(flow), rid(rid) {}

};

vector<edge> g[T];
ii pai[T];
bool vis[T];
bool print[T][T];
int n,m;

void add(int a, int b, int c) {
    g[a].eb(b,c,0,g[b].size()); 
    g[b].eb(a,0,0,g[a].size()-1);
}

int bfs(int s, int t) {
    for(int i = 0; i < T; i++) pai[i] = ii(-1,INF);
    queue<ii> fila;
    fila.emplace(s, INF);

    while(!fila.empty()) {
        ii at = fila.front();
        fila.pop();

        for(int i = 0; i < g[at.fi].size(); i++) {
            edge &edg = g[at.fi][i];
            if(pai[edg.to].fi == -1 and edg.cap - edg.flow) {
                int f = min(at.se, edg.cap - edg.flow);
                fila.emplace(edg.to,f);
                pai[edg.to] = ii(at.fi,i);
                if(edg.to == t) return f;
            }
        }
    }

    return 0;
}

int maxFlow(int s, int t) {
    int f = bfs(s,t);
    int ans = 0;

    while(f) {
        for(int at = t; at != s; at = pai[at].fi) {
            edge &edg = g[pai[at].fi][pai[at].se];
            edg.flow += f;
            edge &redg = g[edg.to][edg.rid];
            redg.flow -= f;
        }

        ans += f;
        f = bfs(s,t);
    }

    return ans;
}

void minCut(int at, int s) {
    vis[at] = 1;

    for(int i = 0; i < g[at].size(); i++) {
        edge &edg = g[at][i];
        int next = edg.to;

        if(print[at][next]) continue;

        if(pai[next].fi == -1 and next != s) {
            cout << at << " " << next << endl;
            print[at][next] = 1;
        }
       
        else if(!vis[next]) minCut(next,s);
    }
}

void init() {
    for(int i = 0; i < T; i++) g[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> n >> m;
    while(n or m) {
        init();
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            add(a,b,c);
            add(b,a,c);
        }

        maxFlow(1,2);
        memset(vis, 0, sizeof vis);
        memset(print , 0, sizeof print);
        minCut(1,1);

        cin >> n >> m;
        if(n or m) cout << endl;
    }

    return 0;
}

