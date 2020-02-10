#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T	= 1e5 + 5;
int seg[20*T], L[20*T], R[20*T];
int volta[T];
int root[T];
vector<int> v(T);
vector<int> ve;
int nodes;

int build(int i, int j) {
    nodes++;
    int at = nodes;
    if(i == j) return seg[at] = 0;
    else {
        int mid = (i+j) >> 1;
        L[at] = build(i,mid);
        R[at] = build(mid+1,j);
    }
    return at;
}

int update(int i, int j, int p, int last) {
    nodes++;
    int at = nodes;

    if(i == j) {
        seg[at] = seg[last]+1;
        return at;
    }

    int mid = (i+j) >> 1;

    if(p <= mid) {
        L[at] = update(i,mid,p,L[last]);
        R[at] = R[last];
    } else {
        L[at] = L[last];
        R[at] = update(mid+1,j,p,R[last]);
    }

    seg[at] = seg[L[at]] + seg[R[at]];
    return at;
}

int query(int node1, int node2, int i, int j, int need) {
    if(i == j) return i;
    int mid = (i+j) >> 1;
    if(seg[L[node1]] - seg[L[node2]] >= need) return query(L[node1],L[node2],i,mid,need);
    else return query(R[node1],R[node2],mid+1,j,need-seg[L[node1]]+seg[L[node2]]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    root[0] = build(1,n);

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        ve.pb(v[i]);
    }

    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());

    for(int i = 1; i <= n; i++) {
        int pos = lower_bound(ve.begin(), ve.end(), v[i]) - ve.begin() + 1;
        volta[pos] = v[i];
        root[i] = update(1,n,pos,root[i-1]);
    }


    while(q--) {
        int l,r,k;
        cin >> l >> r >> k;
        cout << volta[query(root[r],root[l-1],1,n,k)] << endl;
    }

    return 0;
}
