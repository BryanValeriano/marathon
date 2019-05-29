#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,ll> ii;
typedef vector< pair<int,int> > vii;
const ll INF = LLONG_MAX;

const int T = 5e3 + 2;

struct edge {
    int to,rid;
    ll flow, cap;

    edge(int to, ll cap, ll flow, int rid) :
        to(to), cap(cap), flow(flow), rid(rid) {}

};

vector<edge> g[T];
ii pai[T];
int n,m;

void add(int a, int b, ll c) {
    g[a].eb(b,c,0,g[b].size()); 
    g[b].eb(a,0,0,g[a].size()-1);
}

ll bfs(int s, int t) {
    for(int i = 0; i < T; i++) pai[i] = ii(-1,INF);
    queue<ii> fila;
    fila.emplace(s, INF);

    while(!fila.empty()) {
        ii at = fila.front();
        fila.pop();

        for(int i = 0; i < g[at.fi].size(); i++) {
            edge &edg = g[at.fi][i];
            if(pai[edg.to].fi == -1 and edg.cap - edg.flow) {
                ll f = min(at.se, edg.cap - edg.flow);
                fila.emplace(edg.to,f);
                pai[edg.to] = ii(at.fi,i);
                if(edg.to == t) return f;
            }
        }
    }

    return 0;
}

ll maxFlow(int s, int t) {
    ll f = bfs(s,t);
    ll ans = 0;

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

int main() {
    ios::sync_with_stdio(false);
    int a,b;
    ll c;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }

    cout << maxFlow(1,n) << endl;

    return 0;
}

