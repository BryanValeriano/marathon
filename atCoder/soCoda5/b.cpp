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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<ll,ll,int> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 303;

ll dist[T][T];
ll tmp[T];
vii g[T];
bool vis[T];
bool ok[T];
ll n,m,tank;

void dij(int s) {
    vis[s] = 1;
    for(int i = 0; i <= n; i++) {
        dist[s][i] = 1e18;
        tmp[i] = -1e18;
        ok[i] = 0;
    }

    dist[s][s] = 0;
    tmp[s] = tank;
    priority_queue<ti,vti,greater<ti>> pq;
    pq.emplace(0,-tank,s);

    while(!pq.empty()) {
        ti at = pq.top();
        pq.pop();

        ll t,r,u;
        tie(t,r,u) = at;

        if(ok[u]) continue;
        ok[u] = 1;

        for(ii v : g[u]) {
            ll nr = r+v.se;
            ll nt = t;
            if(nr > 0) {
                if(tank < v.se) continue;
                nr = -tank + v.se;
                nt++;
            }
            if(dist[s][v.fi] > nt or (dist[s][v.fi] == nt and tmp[v.fi] < abs(nr))) {
                dist[s][v.fi] = nt;
                pq.emplace(nt,nr,v.fi);
                tmp[v.fi] = abs(nr);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> tank;

    while(m--) {
        int a,b,c; cin >> a >> b >> c;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    int q; cin >> q;
    while(q--) {
        int s,t; cin >> s >> t;
        if(!vis[s] and !vis[t]) {
            if(!vis[s]) dij(s);
            else if(!vis[t]) dij(t);
        }
        if(vis[s]) cout << (dist[s][t] == 1e18? -1 : dist[s][t]) << endl;
        else if(vis[t]) cout << (dist[t][s] == 1e18? -1 : dist[t][s]) << endl;
    }

    return 0;
}

