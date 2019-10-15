#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const ll INF = 0x3f3f3f3f3f3f;

const int T = 1e5 + 5;
ll v[T];
ll seg[4*T];
ll lazy[4*T];
ll small[4*T];
ll big[4*T];
ll a,b,val;
int n,q;

void build(int node, int i, int j) {
    if(i == j) seg[node] = small[node] = big[node] = v[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        small[node] = min(small[2*node],small[2*node+1]);
        big[node] = max(big[2*node],big[2*node+1]);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

void prop(int node, int i, int j) {
    if(!lazy[node]) return;
    seg[node] = max(0ll, seg[node] - (ll)(j-i+1)*lazy[node]);
    big[node] = max(0ll, big[node] - lazy[node]);
    small[node] = max(0ll, small[node] - lazy[node]);

    if(i != j) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        if(big[node] <= val or small[node] >= val) { lazy[node] += val; prop(node,i,j); return; }
    }
    int mid = (i+j) >> 1;
    update(2*node,i,mid);
    update(2*node+1,mid+1,j);
    small[node] = min(small[2*node],small[2*node+1]);
    big[node] = max(big[2*node],big[2*node+1]);
    seg[node] = seg[2*node] + seg[2*node+1];
}

ll query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return query(2*node,i,mid) + query(2*node+1,mid+1,j);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1,1,n);

    int op,aa,bb;
    
    while(q--) {
        cin >> op >> aa >> bb;
        if(op == 1) {
            if(bb < aa) {
                a = 1, b = bb;
                ll ans = query(1,1,n);
                a = aa, b = n; 
                ans += query(1,1,n);
                cout << ans << endl;
            } else {
                a = aa, b = bb;
                cout << query(1,1,n) << endl;
            }
        } else {
            cin >> val;
            if(bb < aa) {
                a = 1, b = bb;
                update(1,1,n);
                a = aa, b = n; 
                update(1,1,n);
            } else {
                a = aa, b = bb;
                update(1,1,n);
            }
            
        }
    }
    
    return 0;
}

