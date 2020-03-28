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
const int T = 2e5+2;
vector<int> g[T];
int n,k,rest;

void bfs() {
    queue<int> fila;
    int cont = 2;
    fila.push(1);

    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();

        while(g[at].size() < (at == 1? k : 2) and cont <= n) {
            g[at].pb(cont);
            g[cont].pb(at);
            fila.push(cont);
            cont++;
        }
    }
}

ii dfs(int u, int pai, int d) {
    ii best = mk(d,u);
    for(int v : g[u]) {
        if(v == pai) continue;
        best = max(best, dfs(v,u,d+1));
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    rest = k-n;
    bfs();

    ii x = dfs(1,1,0);
    x = dfs(x.se,x.se,0);
    cout << x.fi << endl;

    for(int u = 1; u <= n; u++)
        for(int v : g[u])
            if(u < v) cout << u << " " << v << endl;
    return 0;
}

