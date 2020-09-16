#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<ll,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+5;
int x,n,m;
ll t;
ll p[T], temp[T];
ll dist[T][T];
bool vis[T][T];
vector<int> g[T];

void dij(int u) {
    for(int i = 0; i < T; i++)
        for(int j = 0; j < T; j++)
            dist[i][j] = INF;

    dist[u][temp[0]] = p[0];
    priority_queue<ti,vti,greater<ti>> pq;
    pq.emplace(dist[u][temp[0]],temp[0],u);

    while(!pq.empty()) {
        ll d;
        int tt;
        tie(d,tt,u) = pq.top();
        pq.pop();

        if(vis[u][tt]) continue;
        vis[u][tt] = 1;
        //cout << u << " " << tt << " " << d << endl;

        for(int v : g[u]) {
            ll nt = tt+temp[v]+(v==u?0:t);
            ll np = d+p[v];
            if(nt > x or dist[v][nt] < np) continue;
            dist[v][nt] = np;
            pq.emplace(np,nt,v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> x >> n >> m >> t;

    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }


    for(int i = 0; i < n; i++) {
        cin >> temp[i] >> p[i];
        g[i].pb(i);
    }

    dij(0);

    if(dist[0][x] == INF) cout << "It is a trap.\n";
    else cout << dist[0][x] << endl;

    return 0;
}

