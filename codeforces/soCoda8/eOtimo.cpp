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
const ll INF = 1e17;

const int T = 1e3 + 2;
const int N = 2e4 + 10;

int n,m,s,t;
bool vis[T];
bool ok[N];
ll dist[T];
ll L;

vector<int> v[T];
vii edgs;

bool dij(int p, ll qtd) {
    priority_queue<ii,vii,greater<ii>> pq;

    for(int i = 0; i <= n; i++) {
        dist[i] = INF;
        vis[i] = 0;
    }

    int a = 0;
    for(int i = 0; i < edgs.size(); i++) {
        if(ok[i]) {
            if(a > p) edgs[i].se = edgs[i^1].se = INF;
            else if(a < p) edgs[i].se = edgs[i^1].se = 1;
            else edgs[i].se = edgs[i^1].se = 1ll + qtd;
            a++;
        }
    }

    dist[s] = 0;
    pq.emplace(dist[s],s);

    while(!pq.empty()) {
        ii at = pq.top();
        pq.pop();

        int u = at.se;

        if(vis[u]) continue;
        vis[u] = 1;

        if(u == t) return (dist[u] <= L);

        for(int i = 0; i < v[u].size(); i++) {
            ii tmp = edgs[v[u][i]];

            int viz = tmp.fi;
            ll dt = tmp.se;

            if(dist[u] + dt < dist[viz]) {
                dist[viz] = dist[u] + dt;
                pq.emplace(dist[viz],viz);
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> L >> s >> t;
    int q = 0;

    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        if(c == 0) ok[edgs.size()] = 1, q++;

        v[a].pb(edgs.size());
        edgs.eb(b,max(1,c));
        v[b].pb(edgs.size());
        edgs.eb(a,max(1,c));
    }

    ll l = -1;
    ll r = q-1;
    ll ans = -INF;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(dij(mid,0)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    if(ans == -INF) { cout << "NO" << endl; return 0; }

    l = 0;
    r = INF;
    ll ans2 = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(dij(ans,mid)) ans2 = mid, l = mid+1;
        else r = mid-1;
    }

    dij(ans,ans2);
    if(dist[t] != L) { cout << "NO" << endl; return 0; }

    cout << "YES" << endl;
    for(int i = 0; i < edgs.size(); i += 2) {
        cout << edgs[i].fi << " " << edgs[i^1].fi << " " << edgs[i].se << endl;
    }

    return 0;
}

