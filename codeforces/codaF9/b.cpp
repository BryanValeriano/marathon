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
const int T = 1e7+1e6;
const int N = 5e5+2;
map<int,int> last;
int ri[N];
int bag[N];
int root[N];
int seg[T];
int l[T], r[T];
int nodes,pos,a,b,val;

int build(int i, int j) {
    int at = ++nodes;
    seg[at] = INF;
    if(i!=j) {
        int mid = (i+j)>>1;
        l[at] = build(i,mid);
        r[at] = build(mid+1,j);
    }
    return at;
}

int update(int node, int i, int j) {
    int at = ++nodes;
    if(i==j) { seg[at] = val; return at; }
    int mid = (i+j)>>1;
    l[at] = (mid >= pos? update(l[node],i,mid) : l[node]);
    r[at] = (mid < pos? update(r[node],mid+1,j) : r[node]);
    seg[at] = min(seg[l[at]],seg[r[at]]);
    return at;
}

int query(int node, int i, int j) {
    if(i > b or j < a) return INF;
    if(i >= a) return seg[node];
    int mid = (i+j)>>1;
    return min(query(l[node],i,mid),query(r[node],mid+1,j));
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    root[0] = build(1,n);
    for(int i = 1; i <= n; i++) cin >> ri[i];

    for(int i = n; i >= 1; i--) {
        int x = ri[i];
        if(last.count(x)) bag[last[x]] = i;
        last[x] = i;
    }

    for(int i = 1; i <= n; i++) {
        if(bag[i]) {
            pos = bag[i];
            val = i-bag[i];
            root[i] = update(root[i-1],1,n);
        } else root[i] = root[i-1];
    }

    while(q--) {
        cin >> a >> b;
        int x = query(root[b],1,n);
        cout << (x==INF?-1:x) << endl;
    }

    return 0;
}

