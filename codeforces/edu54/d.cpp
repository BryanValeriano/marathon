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
const int T = 3e5 + 4;

struct edge {
    ll p, u, ind;

    bool operator > (const edge &b) const {
        if(p != b.p) return p > b.p;
        return false;
    }

    edge(ll p, ll u, ll ind) :
        p(p), u(u), ind(ind) {}
};

vector<ll>ans;
bool vis[T];
ll dist[T];
vector<edge> g[T];


void dij(int source, int qtd) {
    memset(dist, INF, sizeof dist);
    dist[source] = 0;
    priority_queue< edge, vector<edge>, greater<edge> > pq;
    pq.push(edge(0,source,0));

    while(true) {
        edge davez = edge(-1,-1,-1);
        while(!pq.empty()) {
            edge atual = pq.top();
            pq.pop();
            if(!vis[atual.u]) {
                davez = atual;
                break;
            }
        }

        if(davez.u == -1) return;
        vis[davez.u] = true;
        if(davez.ind != 0) ans.pb(davez.ind);
        if(ans.size() == qtd) return;
        ll atual = davez.u;

        for(int i = 0; i < g[atual].size(); i++) {
            edge filho = g[atual][i];
            ll d = filho.p;
            if(dist[filho.u] > dist[atual] + d) {
                dist[filho.u] = dist[atual] + d;
                pq.push(edge(dist[filho.u], filho.u, filho.ind));
            }
        }
    }
}
                


int main() {
    ios::sync_with_stdio(false);
    ll n, m, k; cin >> n >> m >> k;
    ll u, v, p;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        g[u].pb(edge(p,v,i+1));
        g[v].pb(edge(p,u,i+1));
    }
    dij(1,k);
    
    cout << ans.size() << endl;
    for(auto r : ans) cout << r << " ";
    cout << endl;

    return 0;
}

