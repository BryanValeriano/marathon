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
const int T = 5e5+2;
const int LOG = log2(T)+1;

vector<int> g[T], h[T];
int anc[LOG][T];
ll cost[LOG][T];
int d[T], ans[T], in[T], niv[T];
vector<int> bag;

void dfs(int u) {
    for(int v : g[u]) {
        niv[v] = niv[u]+1;
        dfs(v);
    }
}

void build(int n) {
    dfs(1);
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
            cost[i][j] += cost[i-1][j];
            cost[i][j] = cost[i-1][anc[i-1][j]];
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

void toposort(int n) {
    queue<int> fila;
    for(int i = 1; i <= n; i++) {
        ans[i] = 0;
        if(!in[i]) fila.push(i);
    }
    while(!fila.empty()) {
        int u = fila.front();
        for(int v : h[u]) {
            in[v]--;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> t[i];
        init(n);
        anc[0][1] = 1;
        cost[0][1] = INF;

        for(int i = 0; i < n-1; i++) {
            int a,b,c; cin >> a >> b >> c;
            g[a].pb(b);
            h[b].pb(a);
            in[a]++;
            anc[0][b] = a;
            cost[0][b] = c;
        }

        build(n);

        for(int i = 2; i <= n; i++)
            d[i] = sobe(i,t[i]);

        toposort(n);

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

