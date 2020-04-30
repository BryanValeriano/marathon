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
const int T = 2e5 + 4;
const int N = 1e7;
int root[T];
int seg[N], L[N], R[N];
int nodes, a, b;

int build(int node, int i, int j) {
    if(i == j) return node;
    int mid = (i+j)>>1;
    L[node] = build(++nodes,i,mid);
    R[node] = build(++nodes,mid+1,j);
    return node;
}

int update(int node, int last, int i, int j) {
    if(i >= a and j <= b) { seg[node]++; return node; }
    int mid = (i+j)>>1;
    L[node] = (a<=mid?update(++nodes,L[last],i,mid):L[last]);
    R[node] = (b>mid?update(++nodes,R[last],mid+1,j):R[last]);
    seg[node] = seg[L[node]]+seg[R[node]];
    return node;
}

int query(int node, int i, int j) {
    if(a > b) return 0;
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return query(L[node],i,mid)+query(R[node],mid+1,j);
}

ll sqr(ll x) { return (x*(x-1))>>1; }

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    root[0] = build(0,1,n);

    for(int i = 1; i <= n; i++) {
        cin >> a;
        b = a;
        root[i] = update(++nodes,root[i-1],1,n);
    }

    ll tot = sqr(n);

    while(q--) {
        int l,d,r,u;
        cin >> l >> d >> r >> u;
        a = 1, b = n;
        //left
        ll le = query(root[l-1],1,n);
        //right
        ll ri = query(root[n],1,n)-query(root[r],1,n);
        //up
        a = u+1; b = n;
        ll up = query(root[n],1,n);
        ll upl = query(root[l-1],1,n);
        ll upr = query(root[n],1,n)-query(root[r],1,n);
        //down
        a = 1; b = d-1;
        ll down = query(root[n],1,n);
        ll downl = query(root[l-1],1,n);
        ll downr = query(root[n],1,n)-query(root[r],1,n);
        ll ans = tot-sqr(le)-sqr(ri)-sqr(up)-sqr(down);
        ans += sqr(upl) + sqr(upr) + sqr(downl) + sqr(downr);
        cout << ans << endl;
    }

    return 0;
}

