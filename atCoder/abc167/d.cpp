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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5+3;
int g[T];
vector<int> cycle[T];
ll id[T];
int pai[T], peso[T], low[T], d[T], st[T];
bool vis[T];
int t, sz;

void init() {
    for(int i = 0; i < T; i++) pai[i] = i, peso[i] = 1;
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

void dfs(int u) {
    st[sz++] = u;
    d[u] = low[u] = ++t;
    int v = g[u];

    if(!d[v]) {
        dfs(v);
        low[u] = min(low[u],low[v]);
    } else low[u] = min(low[u],d[v]);

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            join(a,u);
            d[a] = INF;
        } while(a != u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    init();
    for(int i = 1; i <= n; i++) cin >> g[i];
    for(int i = 1; i <= n; i++) if(!d[i]) dfs(i);

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        if(peso[find(i)] > 1) {
            int a = i;
            do {
                id[a] = cycle[find(i)].size();
                cycle[find(i)].pb(a);
                a = g[a];
                vis[a] = 1;
            } while(a != i);
        }
    }

    int at = 1;
    while(k) {
        if(peso[find(at)] > 1) {
            ll x = (k+id[at])%((ll)cycle[find(at)].size());
            cout << cycle[find(at)][x] << endl;
            return 0;
        }
        if(at == g[at]) break;
        at = g[at];
        k--;
    }

    cout << at << endl;

    return 0;
}

