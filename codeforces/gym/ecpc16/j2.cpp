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
const int INF = 1e9+2;
const double PI = acos(-1.0);

const int T = 5e5+2;
const int LOG = log2(T)+3;

vector<ii> g[T];
vector<int> seg[4*T+1];
int anc[LOG][T];
ll cost[LOG][T];
int d[T], niv[T], tank[T];
int tin[T], tout[T];
int t,a,b,ve;

void dfs(int u) {
    tin[u] = ++t;
    for(auto [v,c] : g[u]) {
        if(tin[v]) continue;
        niv[v] = niv[u]+1;
        anc[0][v] = u;
        cost[0][v] = c;
        dfs(v);
    }
    tout[u] = t;
}

void bd(int n) {
    dfs(1);
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
            cost[i][j] = cost[i-1][j];
            cost[i][j] += cost[i-1][anc[i-1][j]];
        }
    }
}

int sobe(int u, ll c) {
    int ans = 0;
    for(int i = LOG-1; i >= 0; i--) {
        if(cost[i][u] <= c) {
            ans += (1<<i);
            c -= cost[i][u];
            u = anc[i][u];
        }
    }
    return ans;
}

void build(int node, int i, int j) {
    if(i==j) {
        seg[node].clear();
        seg[node].pb(d[i]);
    } else {
        int mid = (i+j)>>1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node].clear();
        seg[node].resize(j-i+1);
        merge(seg[2*node].begin(),seg[2*node].end(),
              seg[2*node+1].begin(), seg[2*node+1].end(),
              seg[node].begin());
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) {
        int x = upper_bound(seg[node].begin(),seg[node].end(), ve) - seg[node].begin();
        return x;
    } else {
        int mid = (i+j)>>1;
        return query(2*node,i,mid)+query(2*node+1,mid+1,j);
    }
}

void init(int n) {
    t = 0;
    for(int i = 1; i <= n; i++) {
        cin >> tank[i];
        g[i].clear();
        niv[i] = 0;
        tin[i] = tout[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("car.in","r",stdin);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        init(n);

        anc[0][1] = 1;
        cost[0][1] = INF;
        for(int i = 0; i < n-1; i++) {
            int aa,bb,c; cin >> aa >> bb >> c;
            g[aa].eb(bb,c);
            g[bb].eb(aa,c);
        }

        bd(n);
        for(int i = 1; i <= n; i++)
            d[tin[i]] = niv[i]-sobe(i,tank[i]);

        build(1,1,n);

        for(int i = 1; i <= n; i++) {
            a = tin[i], b = tout[i], ve = niv[i];
            cout << query(1,1,n)-1 << " ";
        }
        cout << endl;
    }
    return 0;
}

