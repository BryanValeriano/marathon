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
const int T = 3e5 + 3;
const ll MOD = 1e9+9;
ll seg[T];
bool leaf[T];
ll f[T];
vii lazy[T];
int a,b;

void build(int node, int i, int j) {
    if(i==j) cin >> seg[node], leaf[node] == 1;
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = (seg[2*node]+seg[2*node+1])%MOD;
    }
}

void push(int node, int x, int y) {
    if(!leaf[node]) lazy[node].eb(x,y);
    seg[node] = (seg[node]+((f[y]-f[x-1]+MOD)%MOD))%MOD;
}

void prop(int node) {
    while(!lazy[node].empty()) {
        int x,y;
        tie(x,y) = lazy[node].back();
        lazy[node].pop_back();
        int md = (x+y)>>1;
        push(2*node,x,md);
        push(2*node+1,md+1,y);
    }
}

void update(int node, int i, int j, int x, int y) {
    if(i >= a and j <= b) push(node,x,y);
    else {
        int mid = (i+j) >> 1;
        prop(node);
        int cut = max(0,min(j,b)-mid);
        if(mid >= a) update(2*node,i,mid,x,y-cut);
        if(mid < b) update(2*node+1,mid+1,j,min(y,y-cut+1),y);
        seg[node] = (seg[2*node]+seg[2*node+1])%MOD;
    }
}

ll query(int node, int i, int j) {
    if(i >= a and j <= b) return seg[node];
    else {
        int mid = (i+j) >> 1;
        prop(node);
        ll ans = 0;
        if(mid >= a) ans = (ans + query(2*node,i,mid))%MOD;
        if(mid < b) ans = (ans + query(2*node+1,mid+1,j))%MOD;
        return ans;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    f[0] = 0;
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++) f[i] = (f[i-1]+f[i-2])%MOD;
    for(int i = 1; i <= n; i++) f[i] = (f[i]+f[i-1])%MOD;
    build(1,1,n);
    while(m--) {
        int op;
        cin >> op >> a >> b;
        if(op&1) update(1,1,n,1,b-a+1);
        else cout << query(1,1,n) << endl;
    }
    return 0;
}

