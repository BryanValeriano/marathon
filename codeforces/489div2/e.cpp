#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,int> ii;
typedef vector< pair<ii,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 10;
ii seg[4*T];
ll lazy[4*T];

ll v[T];
ll acum[T];
ll dist[T];
int a,b,val;

ii best(const ii &a, const ii &b) {
    if(abs(a.fi) < abs(b.fi)) return a;
    return b;
}

void build(int node, int i, int j) {
    if(i == j) seg[node] = mk(dist[i],i);
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);
        seg[node] = best(seg[2*node], seg[2*node+1]);
    }
}

void prop(int node, int i, int j) {
    seg[node].fi += (j-i+1)*lazy[node];

    if(i != j) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int i, int j) {
    prop(node, i, j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) { 
        lazy[node] += val;
        prop(node,i,j);
    } else {
        int mid = (i+j) >> 1;
        update(2*node, i, mid);
        update(2*node+1, mid+1, j);
        seg[node] = best(seg[2*node], seg[2*node+1]);
    }
}

ii query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return ii(INF, INF);
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return best(query(2*node, i, mid), query(2*node+1, mid+1, j));
}

int main() {
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i], acum[i] = v[i];
    for(int i = 1; i <= n; i++) acum[i] += acum[i-1];

    for(int i = 1; i <= n; i++) 
        dist[i] = v[i] - acum[i-1];

    build(1,1,n); 

    int x,y;
    while(q--) {
        cin >> x >> y;

        val = y - v[x];
        v[x] = y;
        
        a = b = x;
        update(1, 1, n); 
        val = -val;
        a = x+1;
        b = n;
        update(1, 1, n);

        a = 1; b = n; 
        ii ans = query(1,1,n);

        if(ans.fi == 0) cout << ans.se << endl;
        else cout << -1 << endl;
    }

    return 0;
}

