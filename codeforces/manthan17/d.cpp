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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+2;
const int LOG = log2(T)+2;
vector<int> g[T];
int anc[LOG][T];
int mask[LOG][T];
int niv[T];
int n;

int sobe(int u, int l) {
    int ans = 0;

    for(int i = LOG-1; i >= 0; i--) {
        if(niv[u]-(1<<i) >= niv[l]) {
            ans |= mask[i][u];
            u = anc[i][u];
        }
    }

    return ans;
}

int lca(int u, int v) {
    if(niv[v] < niv[u]) swap(v,u);
    for(int i = LOG-1; i >= 0; i--)
        if(niv[v]-(1<<i) >= niv[u]) v = anc[i][v];

    if(u==v) return u;

    for(int i = LOG-1; i >= 0; i--) {
        if(anc[i][u] != anc[i][v]) {
            u = anc[i][u];
            v = anc[i][v];
        }
    }

    return (anc[0][u]==anc[0][v]?anc[0][u]:-1);
}

void dfs(int u) {
    for(int v : g[u]) {
        niv[v] = niv[u]+1;
        dfs(v);
    }
}

void build() {
    for(int i = 1; i <= n; i++)
        if(i == anc[0][i])
            dfs(i);

    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
            mask[i][j] |= mask[i-1][j];
            mask[i][j] |= mask[i-1][anc[i-1][j]];
        }
    }
}

//1 = special
//2 = part

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int p,t; cin >> p >> t;
        anc[0][i] = i;
        if(p==-1) continue;
        g[p].pb(i);
        anc[0][i] = p;
        mask[0][i] = t+1;
    }
    build();
    int q; cin >> q;
    while(q--) {
        int t,u,v;
        cin >> t >> u >> v;
        //cout << t << " " << u << " " << v << " == ";
        int l = lca(u,v);
        int a = sobe(u,l);
        int b = sobe(v,l);
        //cout << l << " " << a << " " << b <<endl;
        if(a==b or l ==-1) cout << "NO\n";
        else if(t==1) cout << (l==u && b==1?"YES\n":"NO\n");
        else cout << (((a==1 || l==u) && b==2)?"YES\n" : "NO\n");
    }
    return 0;
}

