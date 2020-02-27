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

const int T = 2e5+100;;
const int M = 1e7 + 1e5;

int root[T], nodes, L[M], R[M], seg[M];
int a,b;

int build(int i, int j) {
    int at = nodes++;

    if(i == j) {
        seg[at] = 0;
    } else {
        int mid = (i+j) >> 1;
        L[at] = build(i,mid);
        R[at] = build(mid+1,j);
        seg[at] = seg[L[at]] + seg[R[at]];
    }

    return at;
}

int update(int node, int i, int j, int p) {
    int at = nodes++;

    if(i == j) {
        seg[at] = seg[node] + 1;
    } else {
        int mid = (i+j) >> 1;
        if(p <= mid) {
            L[at] = update(L[node],i,mid,p);
            R[at] = R[node];
        } else {
            L[at] = L[node];
            R[at] = update(R[node],mid+1,j,p);
        }
        seg[at] = seg[L[at]] + seg[R[at]];
    }

    return at;
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return query(L[node],i,mid) + query(R[node],mid+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    root[0] = build(1, n+10);
    b = n+10;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        x = min(x,n+5);
        int ver = min(i-1, x);
        a = i;
        ans += (ll)query(root[ver],1,n+10);
        root[i] = update(root[i-1],1,n+10,x);
    }

    cout << ans << endl;
    return 0;
}

