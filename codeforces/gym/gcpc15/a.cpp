#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 2e4+4;
const int Z = 17;
int T, gol, p;

vii gols;
vii g[N];
int dp[Z][(1<<Z)];
int dp2[Z][(1<<Z)][2];
int volta[N], ida[N], dist[Z][N];
bool vis[Z][N];

void dij(int u) {
    int ori = ida[u];

    dist[ori][u] = 0;
    priority_queue<ii,vii,greater<ii>>pq;
    pq.emplace(dist[ori][u],u);

    while(!pq.empty()) {
        int d;
        tie(d,u) = pq.top();
        pq.pop();

        if(vis[ori][u]) continue;
        vis[ori][u] = 1;

        for(ii e : g[u]) {
            int v,dd;
            tie(v,dd) = e;
            if(d+dd < dist[ori][v]) {
                dist[ori][v] = d+dd;
                pq.emplace(dist[ori][v],v);
            }
        }
    }
}

int solve(int at, int mask) {
    if(mask==gol) return dist[0][volta[at]];

    int &r = dp[at][mask];
    if(r != -1) return r;
    r = INF;

    for(int i = 0; i < p; i++) {
        if((mask&(1<<i)) or !vis[at][volta[i]]) continue;
        r = min(r, solve(i,mask|(1<<i)) + dist[at][volta[i]]);
    }

    return r;
}

int solve2(int at, int mask, bool taxi) {
    if(mask==gol) return min(dist[0][volta[at]], (taxi? INF : T));

    int &r = dp2[at][mask][taxi];
    if(r != -1) return r;
    r = INF;

    for(int i = 0; i < p; i++) {
        if(!taxi and !(mask&(1<<i))) r = min(r, solve2(i,mask|(1<<i),1)+T);
        if((mask&(1<<i)) or !vis[at][volta[i]]) continue;
        r = min(r, solve2(i,mask|(1<<i),taxi) + dist[at][volta[i]]);
    }

    return r;
}

void build() {
    for(int i = 0; i < p; i++) {
        int x,t; cin >> x >> t;
        gols.eb(x,t);
    }

    sort(gols.begin(),gols.end());
    if(gols[0].fi != 0) gols.eb(0,0);
    sort(gols.begin(),gols.end());
    p = gols.size();
    gol = (1<<p)-1;
    for(int i = 0; i < p; i++) {
        volta[i] = gols[i].fi;
        ida[gols[i].fi] = i;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);
    int n,m,G;

    cin >> n >> p >> m >> G >> T;
    for(int i = 0; i < Z; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = INF;

    build();

    while(m--) {
        int a,b,t; cin >> a >> b >> t;
        g[a].eb(b,t);
        g[b].eb(a,t);
    }

    for(int i = 0; i < p; i++) {
        dij(gols[i].fi);
        G -= gols[i].se;
    }

    int x = solve(0,1);

    if(x <= G) {
        cout << "possible without taxi\n";
        return 0;
    }

    x = solve2(0,1,0);
    if(x <= G) {
        cout << "possible with taxi\n";
        return 0;
    }

    cout << "impossible\n";

    return 0;
}

