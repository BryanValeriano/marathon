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
const int T = 1e5 + 10;
int a = 1;
int b;
ll seg[4*T];
ll lazy[4*T];
int v[T];

void build(int node, int i, int j) {
    if(i == j) seg[node] = v[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);
        seg[node] = max(seg[2*node], seg[2*node+1]);
    }
}

void prop(int node, int i, int j) {
    seg[node] = max(seg[node], lazy[node]);
    if(i != j) {
        lazy[2*node] = max(lazy[2*node], lazy[node]);
        lazy[2*node+1] = max(lazy[2*node+1], lazy[node]);
    }
    lazy[node] = 0;
}

void update(int node, int i, int j, ll val) {
    prop(node, i, j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] = val;
        prop(node,i,j);
        return;
    }
    int mid = (i+j) >> 1;
    update(2*node, i, mid, val);
    update(2*node+1, mid+1, j, val);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}

ll query(int node, int i, int j) {
    prop(node, i, j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return max(query(2*node, i, mid), query(2*node+1, mid+1, j));
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n; 
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, 1, n);
    int q; cin >> q;
    int w,h;
    while(q--) {
        cin >> b >> h;
        ll ans = query(1, 1, n);
        cout << ans << endl;
        update(1, 1, n, ans + h); 
    }
    return 0;
}

