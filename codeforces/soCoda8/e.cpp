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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = 1e18;
const double PI = acos(-1.0);
const int T = 1e3 + 2;
const int N = 2e4 + 10;

int n,m,s,t;
bool vis[T];
bool ok[N];
ll dist[T];
ii pai[T];
ll l;

vector<int> v[T];
vii edgs;

ll dij() {
    priority_queue<ii,vii,greater<ii>> pq;

    for(int i = 0; i <= n; i++) {
        dist[i] = INF;
        vis[i] = 0;
    }

    dist[s] = 0;
    pq.emplace(dist[s],s);

    while(!pq.empty()) {
        ii at = pq.top();
        pq.pop();

        int u = at.se;

        if(vis[u]) continue;
        vis[u] = 1;

        if(u == t) return dist[t];

        for(int i = 0; i < v[u].size(); i++) {
            ii tmp = edgs[v[u][i]];

            int viz = tmp.fi;
            ll dt = tmp.se;

            if(dist[u] + dt < dist[viz]) {
                dist[viz] = dist[u] + dt;
                pai[viz] = mk(u,i);
                pq.emplace(dist[viz],viz);
            }
        }
    }

    return INF;
}

bool erase(int at, ll qtd) {
    if(at == s) return 0;

    int e = v[pai[at].fi][pai[at].se];
    if(ok[e]) {
        edgs[e].se += qtd;
        edgs[e^1].se += qtd;
        return 1;
    }

    return erase(pai[at].fi,qtd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> l >> s >> t;

    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        if(c == 0) ok[edgs.size()] = ok[edgs.size()+1] = 1;

        v[a].pb(edgs.size());
        edgs.eb(b,max(1,c));
        v[b].pb(edgs.size());
        edgs.eb(a,max(1,c));
    }

    ll at = dij();

    while(at < l) {
        if(!erase(t,l-at)) { cout << "NO" << endl; return 0; }
        at = dij();
    }

    if(at > l) { cout << "NO" << endl; return 0; }

    cout << "YES" << endl;
    for(int i = 0; i < edgs.size(); i += 2) {
        cout << edgs[i].fi << " " << edgs[i^1].fi << " " << edgs[i].se << endl;
    }

    return 0;
}

