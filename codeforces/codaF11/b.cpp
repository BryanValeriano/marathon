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
const int T = 1e3+3;
vector<int> g[T];
int d[2][T];

void bfs(int u, int o) {
    queue<int> fila;
    fila.push(u);
    int x = u;

    while(!fila.empty()) {
        u = fila.front();
        fila.pop();
        for(int v : g[u]) {
            if(v != x and !d[o][v]) {
                d[o][v] = d[o][u]+1;
                fila.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,s,t;
    cin >> n >> m >> s >> t;

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    bfs(s,0);
    bfs(t,1);
    int ok = d[0][t];
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int nok = min(d[0][i]+d[1][j]+1,d[1][i]+d[0][j]+1);
            if(nok >= ok) ans++;
        }
    }

    cout << ans-m << endl;
    return 0;
}

