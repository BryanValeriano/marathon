#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;
const int N = 5e7;

int tin[T], tout[T], alt[T], root[T];
int L[N], R[N], seg[N];
int t,nodes,a,b,n;
vi g[T];
vi alts[T];
ll ans = 0;

void lin(int u, int pai, int h) {
    tin[u] = ++t;
    alt[t] = h;

    for(int v : g[u]) {
        if(v==pai) continue;
        lin(v,u,h+1);
    }

    tout[u] = t;
}

int build(int l, int r) {
    int at = nodes++;

    if(nodes >= N) {
        cout << " FUCK\n";
        exit(0);
    }

    if(l == r) {
        seg[at] = 0;
    } else {
        int m = (l+r)>>1;
        L[at] = build(l,m);
        R[at] = build(m+1,r);
        seg[at] = 0;
    }

    return at;
}

int update(int i, int l, int r, int p) {
    int at = nodes++;

    if(nodes >= N) {
        cout << " FUCK\n";
        exit(0);
    }

    if(l == r) {
        seg[at] = seg[i]+1;
    } else {
        int m = (l+r)>>1;
        L[at] = (p <= m? update(L[i],l,m,p) : L[i]);
        R[at] = (p <= m? R[i] : update(R[i],m+1,r,p));
        seg[at] = seg[L[at]] + seg[R[at]];
    }

    return at;
}

int que(int i, int l, int r, int l2, int r2) {
    if(r < l2 or l > r2) return 0;
    if(l >= l2 and r <= r2) return seg[i];
    else {
        int m = (l+r)>>1;
        return que(L[i],l,m,l2,r2) + que(R[i],m+1,r,l2,r2);
    }
}

ll query(int l, int r, int l2, int r2) {
    if(r < l) return 0;
    ll top = que(root[r],1,n,l2,r2);
    ll low = que(root[max(l-1,0)],1,n,l2,r2);
    return top-low;
}

void smallToL(int u, int pai, int h) {
    int l = tin[u]+1;
    int r = 0;
    int l2, r2;

    for(int v : g[u]) {
        if(v == pai) continue;
        smallToL(v,u,h+1);
        l2 = tin[v], r2 = tout[v];

        if(alts[v].size() > alts[u].size()) {
            swap(alts[v],alts[u]);
            swap(l,l2);
            swap(r,r2);
        }

        for(int x : alts[v]) {
            int H = x-h;
            if(H >= b) continue;
            int needL = max(1,a-H)+h;
            int needR = b-H+h;
            ans += query(l,r,needL,needR);
            //cout << u << " " << l << " " << r << " " << needL << " " << needR << " = ";
            //cout << query(l,r,needL,needR) << endl;
            alts[u].pb(x);
        }

        l = min(l,l2);
        r = max(r,r2);
    }

    alts[u].pb(h);
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("awesome.in", "r", stdin);
    int tc; cin >> tc;

    while(tc--) {
        int l,r;
        cin >> n >> l >> r;
        b = (n-1)-l, a = (n-1)-r;

        for(int i = 1; i <= n; i++) g[i].clear(), alts[i].clear();
        t = 0, nodes = 0, ans = 0;

        for(int i = 0; i < n-1; i++) {
            int x,y; cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        lin(1,1,1);
        for(int i = 1; i <= n; i++)
            if(alt[i] > a and alt[i] > 1)
                ans += min(b+1,alt[i])-max(a,1);

        root[0] = build(1,n);
        for(int i = 1; i <= n; i++)
            root[i] = update(root[i-1],1,n,alt[i]);

        smallToL(1,1,1);
        cout << ans << endl;
        //if(a==0) cout << " aqui tbm\n";
    }

    return 0;
}

