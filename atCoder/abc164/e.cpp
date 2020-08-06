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
typedef tuple<ll,int,int> tl;
typedef vector<tl> vtl;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int FULL = 2500 + 3;
const int T = 55;
ll dist[T][FULL+10];
bool vis[T][FULL+10];
vtl g[T];
ii ecg[T];
ll ans[T];
int n,m;
int s;

ll dij() {
    memset(dist, INF, sizeof dist);
    memset(vis, 0, sizeof vis);

    dist[1][min(s,FULL)] = 0;
    priority_queue<tl,vtl,greater<tl>> pq;
    int fdp = min(s,FULL);
    pq.emplace(0ll,fdp,1);
    int falta = n-1;

    while(falta) {
        tl at = pq.top();
        pq.pop();
        ll temp; int tank,u;
        tie(temp,tank,u) = at;

        if(vis[u][tank]) continue;
        vis[u][tank] = 1;
        if(!ans[u] and u > 1) ans[u] = temp, falta--;


        for(auto nxt : g[u]) {
            int v,c; ll t;
            tie(t,c,v) = nxt;
            ll ok = 0;
            for(ll j = 0; ok < FULL; j++) {
                ok = j*ecg[u].fi+tank-c;
                ok = min(ok, (ll)FULL);
                if(ok < 0) continue;
                ll tt = temp + t + j*ecg[u].se;
                if(dist[v][ok] > tt) {
                    dist[v][ok] = tt;
                    pq.emplace(tt,ok,v);
                }
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s;

    for(int i = 0; i < m; i++) {
        int u,v,a,b;
        cin >> u >> v >> a >> b;
        g[u].eb(b,a,v);
        g[v].eb(b,a,u);
    }

    for(int i = 1; i <= n; i++) {
        int c,d; cin >> c >> d;
        ecg[i] = mk(c,d);
    }

    dij();
    for(int i = 2; i <= n; i++) cout << ans[i] << endl;


    return 0;
}

