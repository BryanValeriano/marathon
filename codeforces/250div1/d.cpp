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

const int T = 1e5 + 5;
ll v[T];
int n,m,a,b,op;

ll val;
ll seg[4*T];
ll lazy[4*T];
int ass[4*T];
ll small[4*T];
ll big[4*T];

void build(int node, int i, int j) {
    if(i == j) seg[node] = big[node] = small[node] = v[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = seg[2*node] + seg[2*node+1];
        big[node] = max(big[2*node], big[2*node+1]);
        small[node] = min(small[2*node], small[2*node+1]);
    }
}

void prop(int node, int i, int j) {
    if(!ass[node]) return;

    small[node] = big[node] = lazy[node];
    seg[node] = (ll)(j-i+1)*lazy[node];

    if(i != j) {
        lazy[2*node] = lazy[2*node+1] = lazy[node];
        ass[2*node] = ass[2*node+1] = 1;
    }

    lazy[node] = 0;
    ass[node] = 0;
}

void update(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a or (op == 2 and big[node] < val)) return;
    else if(i >= a and j <= b and big[node] == small[node]) {
        if(op == 2) lazy[node] = big[node]%val;
        else lazy[node] = val;
        ass[node] = 1;
        prop(node,i,j);
    } else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = seg[2*node] + seg[2*node+1];
        big[node] = max(big[2*node], big[2*node+1]);
        small[node] = min(small[2*node], small[2*node+1]);
    }
}

ll query(int node, int i, int j) {
    prop(node, i, j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return query(2*node,i,mid) + query(2*node+1,mid+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1,1,n);

    while(m--) {
        cin >> op >> a >> b;
        if(op == 1) cout << query(1,1,n) << endl;
        else if(op == 2) cin >> val, update(1,1,n);
        else val = b, b = a, update(1,1,n);
    }

    return 0;
}

