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
const int T = 1e5 + 4;

int v[T];
int point[T];
int seg[4*T];
int lazy[4*T];
vector<int> g[T];
int a,b,val;

void build(int node, int i, int j) {
    if(i == j) seg[node] = lazy[node] = 0;
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = lazy[node] = 0;
    }
}

void init(int n, int s) {
    build(1,0,n);
    for(int i = 0; i < T; i++) {
        point[i] = 0;
        g[i].clear();
    }
}

void prop(int node, int i, int j) {
    if(lazy[node] == 0) return;
    seg[node] += lazy[node];
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
        lazy[node] += val;
        prop(node,i,j);
        return;
    }
    int mid = (i+j) >> 1;
    update(2*node,i,mid);
    update(2*node+1,mid+1,j);
    seg[node] = max(seg[2*node],seg[2*node+1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;

    while(tc--) {
        int n,s; cin >> n >> s;
        init(n,s);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            g[v[i]].pb(i);
        }

        int ans = 0;

        for(int r = 0; r < n; r++) {
            int l = (point[v[r]]-s >= 0? g[v[r]][point[v[r]]-s] : -1);
            int ll = (point[v[r]]-s-1 >= 0? g[v[r]][point[v[r]]-s-1] : -1);
            point[v[r]]++;

            if(~l) {
                a = min(ll+1,l), b = l;
                val = -s;
                update(1,0,n);
            }

            a = l+1, b = r;
            val = 1;
            update(1,0,n);

            ans = max(ans,seg[1]);
       }

        cout << "Case #" << ++cont << ": " << ans << endl;
    }
    return 0;
}

