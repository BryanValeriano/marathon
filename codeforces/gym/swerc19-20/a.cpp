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
typedef tuple<ll,ll,ll> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const int Z = 105;
const int ZZ = 1e3+5;
int ini,fim;

ll B, T, n;
ll C[Z];
ll X[ZZ], Y[ZZ];
vii g[ZZ];
vector<ll> eucl[ZZ];
ll dist[ZZ][Z];
bool vis[ZZ][Z];

ll euclid(int u, int v) {
    return ceil(sqrt((X[u]-X[v])*(X[u]-X[v])+(Y[u]-Y[v])*(Y[u]-Y[v])));
}

ll dij() {
    memset(dist,INF,sizeof dist);
    dist[ini][0]= 0;
    priority_queue<ti,vti,greater<ti>> pq;
    pq.emplace(0,0,ini);

    while(!pq.empty()) {
        ti at = pq.top();
        pq.pop();
        int node;
        ll co2, d;
        tie(co2,d,node) = at;

        if(node == fim) return co2;
        if(vis[node][d]) continue;
        vis[node][d] = 1;

        for(int j = 0; j < g[node].size(); j++) {
            ll nCo2, nD, v;
            tie(v,nCo2) = g[node][j];
            nD = eucl[node][j];
            nCo2 += co2;
            nD += d;
            if(nD > B or dist[v][nD] < nCo2) continue;
            dist[v][nD] = nCo2;
            pq.emplace(nCo2,nD,v);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int xi,yi,xf,yf;
    cin >> xi >> yi >> xf >> yf;
    cin >> B >> C[0] >> T;
    for(int i = 1; i <= T; i++) cin >> C[i];

    cin >> n;
    ini = n;
    fim = n+1;
    X[ini] = xi;
    Y[ini] = yi;
    X[fim] = xf;
    Y[fim] = yf;
    eucl[ini].pb(fim);
    g[ini].eb(fim,0);

    for(int i = 0; i < n; i++) {
        int l;
        cin >> X[i] >> Y[i] >> l;

        g[ini].eb(i,0);
        eucl[ini].eb(i);

        g[i].eb(fim,0);
        eucl[i].eb(fim);

        for(int j = 0; j < l; j++) {
            int v,p; cin >> v >> p;
            g[i].eb(v,p);
            g[v].eb(i,p);
            eucl[i].eb(v);
            eucl[v].eb(i);
        }
    }

    for(int i = 0; i <= fim; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            eucl[i][j] = euclid(i,eucl[i][j]);
            g[i][j].se = eucl[i][j]*C[g[i][j].se];
        }
    }

    cout << dij() << endl;

    return 0;
}

