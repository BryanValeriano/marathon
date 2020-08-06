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
const int T = 1e5 + 3;
const int N = 21;
int lazy[4*T];
ll sum[4*T];
int seg[4*T][N];
int n,a,b,val;

void merge(int node, int l, int r) {
    sum[node] = 0;
    for(int k = 1, casa = 0; casa < N; k <<= 1, casa++) {
        seg[node][casa] = (seg[l][casa]+seg[r][casa]);
        sum[node] += (ll)seg[node][casa]*(ll)k;
    }
}

void build(int node, int i, int j) {
    if(i == j) {
        int x; cin >> x;
        sum[node] = x;
        for(int k = 1, casa = 0; casa < N; k <<= 1, casa++)
            if(x&k) seg[node][casa]++;
    } else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        merge(node,2*node,2*node+1);
    }
}

void prop(int node, int i, int j) {
    if(!lazy[node]) return;
    sum[node] = 0;

    for(int k = 1, casa = 0; casa < N; k <<= 1, casa++) {
        if(lazy[node]&k) seg[node][casa] = (j-i+1)-seg[node][casa];
        sum[node] += (ll)seg[node][casa]*(ll)k;
    }

    if(i != j) {
        lazy[2*node] ^= lazy[node];
        lazy[2*node+1] ^= lazy[node];
    }

    lazy[node] = 0;
}


void update(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] ^= val;
        prop(node,i,j);
        return;
    }
    int mid = (i+j)>>1;
    update(2*node,i,mid);
    update(2*node+1,mid+1,j);
    merge(node,2*node,2*node+1);
}

ll query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return sum[node];
    int mid = (i+j)>>1;
    return query(2*node,i,mid)+query(2*node+1,mid+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    build(1,1,n);
    int q; cin >> q;
    while(q--) {
        int op;
        cin >> op >> a >> b;
        if(op==2) {
            cin >> val;
            update(1,1,n);
        } else cout << query(1,1,n) << endl;
    }
    return 0;
}
