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
typedef vector<ii> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const ll LINF = LLONG_MAX;
const double PI = acos(-1.0);

const int T = 1e3+2;
const int N = 1e4+2;
ll dp[N][T];
ll dist[N][T];
bool vis[N][T];
int island[N];
int n,m,G,B;

ll solve(int at, int g) {
    if(at > m) return LINF;
    if(island[at]==n) return 0;

    ll &r = dp[at][g];
    if(r!=-1) return r;

    ll cost = 0;
    r = LINF;

    if(!g) cost = B, g = G;

    ll x = island[at+1]-island[at];
    ll y = island[at]-island[at-1];

    if(g >= x)
        r = min(r, solve(at+1, g-x)+cost+x);
    if(g >= y)
        r = min(r, solve(at-1, g-y)+cost+y);

    return r;
}

ll tmp() {
    priority_queue<ti, vti,greater<ti>> lista;
    lista.emplace(n,1,G);

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= G; j++)
            dist[i][j] = LINF;

    while(!lista.empty()) {
        ti u = lista.top();
        lista.pop();

        ll d;
        int at,g;
        tie(d,at,g) = u;
        d -= (n-island[at]);

        if(vis[at][g]) continue;
        vis[at][g] = 1;
        if(at == m) return d;
        if(!g) d += B, g = G;

        ll x = island[at+1]-island[at];
        ll xx = (n-island[at+1]);
        ll y = island[at]-island[at-1];
        ll yy = (n-island[at-1]);

        if(g >= x and dist[at+1][g-x] > d+x) {
            dist[at+1][g-x] = d+x;
            lista.emplace(dist[at+1][g-x]+xx,at+1,g-x);
        }
        if(g >= y and dist[at-1][g-y] > d+y) {
            dist[at-1][g-y] = d+y;
            lista.emplace(dist[at-1][g-y]+yy,at-1,g-y);
        }

    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    island[0] = -INF;
    for(int i = 1; i <= m; i++) cin >> island[i];
    sort(island,island+m+1);
    cin >> G >> B;
    //ll ans = solve(1,G);
    //cout << (ans >= LINF? -1 : ans) << endl;
    cout << tmp() << endl;
    return 0;
}

