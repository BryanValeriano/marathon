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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e3+2;

vii g[T];
vti e;
ll tam[T];
ll cost[T];
ll interno;
int vis[T];
int vez, prob, n;

bool cut(int a, int b) {
    if(a > b) swap(a,b);
    ll x,y,ig;
    tie(x,y,ig) = e[prob];
    return(a==x and b==y);
}

void dfs(int u) {
    vis[u] = vez;
    cost[u] = 0;
    tam[u] = 1;
    for(auto [v,w] : g[u]) {
        if(cut(u,v) or vis[v] == vez) continue;
        dfs(v);
        cost[u] += tam[v]*w + cost[v];
        tam[u] += tam[v];
    }
}

ll reroot(int u) {
    vis[u] = vez;
    ll ans = cost[u];

    for(auto [v,w] : g[u]) {
        if(cut(u,v)) continue;
        if(vis[v] != vez) {
            cost[u] -= tam[v]*w+cost[v];
            tam[u] -= tam[v];
            tam[v] += tam[u];
            cost[v] += tam[u]*w+cost[u];
            ans = min(ans,reroot(v));
            cost[v] -= tam[u]*w+cost[u];
            tam[v] -= tam[u];
            tam[u] += tam[v];
            cost[u] += tam[v]*w+cost[v];
            interno += (tam[u]-tam[v])*tam[v]*w;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int x,y,z; cin >> x >> y >> z;
        g[x].eb(y,z);
        g[y].eb(x,z);
        if(x > y) swap(x,y);
        e.eb(x,y,z);
    }

    ll ans = LLONG_MAX;

    for(prob = 0; prob < n-1; prob++) {
        ll a,b,z;
        tie(a,b,z) = e[prob];

        interno = 0;
        vez++;
        dfs(a);
        ll qtdA = tam[a];
        vez++;
        ll menorA = reroot(a);
        ll internoA = interno;

        interno = 0;
        vez++;
        dfs(b);
        ll qtdB = tam[b];
        vez++;
        ll menorB = reroot(b);
        ll internoB = interno;

        ans = min(ans, menorA*qtdB + menorB*qtdA + z*qtdA*qtdB + internoA + internoB);
    }

    cout << ans << endl;

    return 0;
}

