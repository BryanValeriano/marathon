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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e6 + 4;
int n,m,sz,t;

bool vis[T];
int d[T], low[T], st[T], pai[T], peso[T];
ll dp[T];
vii tmp[T];
vii g[T];
vector<ll> pega[T];
vector<ll> seq;
ll ans;

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

ll bb(ll x) {
    ll l = 0;
    ll r = x;
    ll ok = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if((mid*(mid+1)>>1) <= x) ok = mid, l = mid+1;
        else r = mid-1;
    }

    return ok;
}

ll solve(int u) {
    if(~dp[u]) return dp[u];

    ll best = 0;
    ll fr = 0;

    for(ll x : pega[u]) {
        ll qtd = bb(x);
        fr += x*(qtd+1) - seq[qtd];
    }


    for(ii x : g[u]) {
        ll tent = 0;
        tent = solve(x.fi) + x.se;
        if(tent > best) best = tent;
    }

    return dp[u] = best+fr;
}

void dfs(int u) {
    vis[u] = 1;
    st[sz++] = u;
    d[u] = low[u] = t++;

    for(ii x : tmp[u]) {
        int v = x.fi;
        if(!vis[v]) {
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else low[u] = min(low[u],d[v]);
    }

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            join(u,a);
            d[a] = INF;
        } while(a != u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    init();
    cin >> n >> m;
    seq.pb(0);
    seq.pb(1);

    for(ll i = 2; seq[i-1] < 1e8; i++) seq.pb(seq[i-1] + i);
    for(int i = 1; i < seq.size(); i++) seq[i] += seq[i-1];

    for(int i = 0; i < m; i++) {
        int a,b,w; cin >> a >> b >> w;
        tmp[a].eb(b,w);
    }

    int s; cin >> s;
    dfs(s);

    for(int i = 1; i <= n; i++) {
        int grup = find(i);
        for(ii x : tmp[i]) {
            int y = find(x.fi);
            if(y == grup) pega[grup].pb(x.se);
            else g[grup].eb(y,x.se);
        }
    }

    cout << solve(s) << endl;

    return 0;
}

