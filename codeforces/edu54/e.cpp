#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 3e5 + 10;
vector<int> g[T];
ll seg[4*T];
ll lazy[4*T];
vii q[T];
int n, a ,b;
bool vis[T];
int h[T];
ll ans[T];

void prop(int node, int i, int j) {
    seg[node] += lazy[node] * (j-i+1);

    if(i != j) { 
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int i, int j, int val) {
    prop(node,i,j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] += val;
        prop(node,i,j);
    }
    else {
        int mid = (i+j) >> 1;
        update(2*node, i, mid, val);
        update(2*node+1, mid+1, j, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

ll query(int node, int i, int j) {
    prop(node, i, j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return query(2*node, i, mid) + query(2*node+1, mid+1, j);
}

void dfs(int u) {
    vis[u] = true;
    for(ii x : q[u]) {
        a = h[u]; b = min(T-1, h[u] + x.fi);
        update(1,0,n,x.se);
    }

    a = b = h[u];
    ans[u] = query(1,0,n);

    for(int v : g[u])
        if(!vis[v]) {
            h[v] = h[u] + 1;
            dfs(v);
        }

    for(ii x : q[u]) {
        a = h[u]; b = min(T-1, h[u] + x.fi);
        update(1,0,n, -x.se);
    }
}


void solve() {
    h[1] = 1;
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

void read() {
    int u, v, x, m;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> x;
        q[u].eb(v,x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    read();
    solve();
    return 0;
}

