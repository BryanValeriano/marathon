#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e4+5;
vii g[T];
ll dist[T];
bool qtd[T], vis[T];

void dij(int u) {
    dist[u] = 0;
    priority_queue<ii,vii,greater<ii>>pq;
    pq.emplace(dist[u],u);

    while(!pq.empty()) {
        ll d;
        tie(d,u) = pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(ii e : g[u]) {
            int v;
            ll dd;
            tie(v,dd) = e;
            if(d+dd == dist[v]) qtd[v] = 1;
            if(d+dd < dist[v]) {
                dist[v] = d+dd;
                qtd[v] = qtd[u];
                pq.emplace(dist[v],v);
            }

        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    while(k--) { int x; cin >> x; }
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }
    dij(1);
    cout << (qtd[n]? "yes" : "no") << endl;
    return 0;
}

