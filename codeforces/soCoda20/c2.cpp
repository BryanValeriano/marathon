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
const int T = 5e5 + 10;

vector<int> g[T];
int tin[T], tout[T];
int seg[4*T + 10];
int lazy[4*T + 10];
int n,t,a,b,val;


void dfs(int u, int pai) {
    tin[u] = ++t;
    for(int v : g[u]) {
        if(v == pai) continue;
        dfs(v,u);
    }
    tout[u] = t;
}

void prop(int node, int i, int j) {
    if(!lazy[node]) return;
    seg[node] = lazy[node]-1;

    if(i != j) {
        lazy[2*node] = lazy[2*node+1] = lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return;

    if(i >= a and j <= b) {
        lazy[node] = val;
        prop(node,i,j);
        return;
    }

    int mid = (i+j) >> 1;

    update(2*node,i,mid);
    update(2*node+1,mid+1,j);

    if(val == 1) seg[node] = 0;
    else seg[node] = min({seg[2*node],seg[2*node+1],seg[node]});
}

int query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return 1;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return min(query(2*node,i,mid),query(2*node+1,mid+1,j));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1,1);
    int q; cin >> q;

    while(q--) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            a = tin[x];
            b = tout[x];
            val = 2;
            update(1,1,n);
        }
        else if(op == 2) {
            a = tin[x];
            b = tin[x];
            val = 1;
            update(1,1,n);
        } else {
            a = tin[x];
            b = tout[x];
            cout << query(1,1,n) << endl;
        }
    }

    return 0;
}

