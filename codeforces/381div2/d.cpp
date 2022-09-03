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
const int T = 2e5+5;
const int LOG = log2(T)+2;
vii g[T];
int a[T], s[T], ans[T], niv[T];
int anc[T][LOG];
ll sum[T][LOG];
set<ii> bag[T];
int n;

void dfs(int u) {
    for(ii e : g[u]) {
        int v,w;
        tie(v,w) = e;
        anc[v][0] = u;
        sum[v][0] = w;
        niv[v] = niv[u]+1;
        dfs(v);
    }
}

void build() {
    for(int i = 0; i < LOG; i++)
        for(int j = 0; j <= n; j++) {
            anc[j][i] = 1;
        }

    niv[1] = 1;
    dfs(1);
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
            sum[j][i] = sum[j][i-1] + sum[anc[j][i-1]][i-1];
        }
    }
}

int binLift(int u) {
    int aux = a[u];
    int tmp = 0;
    int f = u;

    for(int i = LOG-1; i >= 0; i--) {
        if(aux >= tmp+sum[u][i]) {
            tmp += sum[u][i];
            u = anc[u][i];
        }
    }

    return u;
}

void solve(int u) {
    for(ii e : g[u]) {
        int v,w;
        tie(v,w) = e;
        solve(v);
        if(bag[v].size() > bag[u].size()) swap(bag[v], bag[u]);
        while(!bag[v].empty()) {
            bag[u].insert(*bag[v].begin());
            bag[v].erase(bag[v].begin());
        }
    }
    ans[u] = bag[u].size();
    while(!bag[u].empty()) {
        auto tmp = bag[u].lower_bound(mk(u,0));
        if(tmp != bag[u].end() && tmp->fi == u) {
            bag[u].erase(tmp);
        } else break;
    }
    if(s[u] != u) bag[u].emplace(s[u],u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++) {
        int p,w;
        cin >> p >> w;
        g[p].eb(i,w);
    }
    build();
    for(int i = 1; i <= n; i++) {
        s[i] = binLift(i);
    }
    solve(1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

