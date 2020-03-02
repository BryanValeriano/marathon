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
const int T = 1e5 + 5;

vii g[T];
ll dist[T];
int pai[T];
bool vis[T];
int n,m;

bool dij() {
    dist[1] = 0;
    priority_queue<ii,vii,greater<ii>>pq;
    pq.emplace(0,1);

    while(!pq.empty()) {
        ii at = pq.top();
        pq.pop();

        int u = at.se;
        ll d = at.fi;

        if(vis[u]) continue;
        if(u == n) return 1;
        vis[u] = 1;

        for(auto v : g[at.se]) {
            ll vd = v.se;
            int viz = v.fi;
            if(dist[u] + vd < dist[viz]) {
                dist[viz] = dist[u] + vd;
                pai[viz] = u;
                pq.emplace(dist[viz],viz);
            }
        }

    }

    return 0;

}

void build(int at) {
    if(at != 1) build(pai[at]);
    cout << at << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) dist[i] = INF;

    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    if(!dij()) cout << -1 << endl;
    else { build(n); cout << endl; }
    return 0;
}

