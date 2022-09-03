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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;

int a[T], d[T], low[T], t = 0;
vector<int> g[T];
bool vis[T];
set<ii> ponte;
set<ii> bag;

void botaPonte(int u, int v) {
    if(u > v) swap(u,v);
    ponte.emplace(u,v);
}

void dfs(int u, int p) {
    d[u] = low[u] = ++t;
    vis[u] = 1;
    for(int v : g[u]) {
        if(!vis[v] and v != p) {
            dfs(v,u);
            if(low[v] > d[u]) botaPonte(u,v);
            low[u] = min(low[v], low[u]);
        } else if(v != p) low[u] = min(low[u], d[v]);
    }
}

void solve(int x) {
    priority_queue<int> pq;
    pq.push(-x);
    vis[x] = 1;

    cout << x;
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        u = -u;
        if(u != x) cout << " " << u;
        for(int v : g[u]) {
            if(!vis[v]) {
                pq.push(-v);
                vis[v] = 1;
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    while(m--) {
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1);
    memset(vis,0,sizeof vis);

    for(int i = 0; i < n; i++) cin >> a[i];
    bool ans = 0;

    for(int i = n-1; i > 0 && !ans; i--) {
        bag.emplace(a[i],i);
        int u = a[i];
        int v = a[i-1];
        if(u > v) swap(u,v);
        if(!ponte.count(mk(u,v))) {
            auto x = bag.lower_bound(mk(a[i-1], 0));
            if(x != bag.begin()) x--;
            if(x != bag.end() && x->fi < a[i-1]) {
                //swap(a[i-1], a[x->se]);
                for(int j = i-1; j < x->se; j++) swap(a[j],a[j+1]);
                ans = 1;
                cout << " quale\n";
            }
        }
    }

    if(ans) for(int i = 0; i < n; i++) cout << a[i] << (i+1 < n? ' ' : '\n');
    else if(a[0] != n) solve(a[0]+1);
    else cout << -1 << endl;
    return 0;
}
