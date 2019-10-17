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

const int T = 1e5 + 8;
vii seg[4*T];
vii sad[4*T];
vii col[4*T];
int maxi[4*T];

int v[T];
int a,b;
int cool;

void monta(int node) {
    int mini = INF;
    int ok = 0;
    bool bom = 0;

    for(auto x : seg[2*node]) {
        mini = min(mini,x.fi);
        seg[node].eb(mini,x.se);
    }
    for(auto x : seg[2*node+1]) {
        mini = min(mini,x.fi);
        seg[node].eb(mini,x.se);
    }

    for(auto x : sad[2*node]) {
        ok = max(ok, x.fi/2 + (x.fi&1));
        if(x.fi < ok) bom = 1;
        col[node].eb(bom,x.se);
        sad[node].eb(x);
    }
    for(auto x : sad[2*node+1]) {
        ok = max(ok, x.fi/2 + (x.fi&1));
        if(x.fi < ok) bom = 1;
        col[node].eb(bom,x.se);
        sad[node].eb(x);
    }

    maxi[node] = max(maxi[2*node],maxi[2*node+1]);
}

void build(int node, int i, int j) {
    if(i == j) {
        seg[node].eb(v[i],i);
        sad[node].eb(v[i],i);
        col[node].eb(0,i);
        maxi[node] = (v[i]/2 + (v[i]&1));
    } else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        monta(node);
    }
}

int bin(int node, int gol) {
    int l = 0;
    int r = seg[node].size()-1;
    int ans = r;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(seg[node][mid].fi < gol) ans = mid, r = mid-1;
        else l = mid+1;
    }

    if(seg[node][ans].fi < gol) return seg[node][ans].se;
    else return INF;
}

int query(int node, int i, int j) {
    if(i > b or j < a) return INF;
    if(i >= a and j <= b) {
        auto x = bin(node,cool);
        auto z = lower_bound(col[node].begin(), col[node].end(), ii(1,0));
        int zz = INF;
        if(z != col[node].end()) zz = z->se;
        cool = max(cool, maxi[node]);
        return min(xx,zz);
    }
    int mid = (i+j) >> 1;
    return min(query(2*node+1,mid+1,j), query(2*node,i,mid));
}


int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1,1,n);

    for(int i = 1; i <= n; i++) {
        cool = v[i]/2;
        if(v[i]&1) cool++;

        a = i, b = n;
        int z = query(1,1,n);

        if(z == INF) {
            a = 1, b = n;
            z = query(1,1,n);
            z += (n-i);
            if(z >= INF) {
                z = query(1,1,n);
                z += (n-i) + n;
            }
        } else z -= i;

        cout << (z >= INF? -1 : z) << " ";
    }

    cout << endl;

    return 0;
}

