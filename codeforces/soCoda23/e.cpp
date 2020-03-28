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
const int T = 1e5 + 3;

vector<int> g[T];
queue<int> fila;
int dist[2][T];
bool isD[T];
int n,m,d;

ii dfs(int u, int pai, int dd, int op) {
    ii best = mk((isD[u]? dd : -1),u);
    dist[op][u] = dd;
    for(int v : g[u]) {
        if(v == pai) continue;
        best = max(best,dfs(v,u,dd+1,op));
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dist, INF, sizeof dist);
    cin >> n >> m >> d;

    int ok = 0;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        ok = x;
        isD[x] = 1;
    }

    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ii x = dfs(ok,ok,0,0);
    ii y = dfs(x.se,x.se,0,0);
    dfs(y.se,y.se,0,1);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(max(dist[0][i],dist[1][i]) <= d) ans++;
    cout << ans << endl;

    return 0;
}

