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

const int T = 1e3 + 3;
vector<int> g[T];
int sob[T][T];
int cor[T][T];
int pai[T][T];
int dist[T][T];
int n,m;
int ori;

void dfs(int u) {
    cor[ori][u] = 1;

    for(int v : g[u]) {
        if(!cor[ori][v]) {
            pai[ori][v] = u;
            dist[ori][v] = dist[ori][u] +1;
            dfs(v);
        }

        else if(v == ori and cor[ori][v] == 1)
            if(dist[ori][u] < sob[ori][u])
                sob[ori][u] = dist[ori][u];
    }

    cor[ori][u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    memset(sob, INF, sizeof sob);

    for(int i = 0; i < m; i++) {
        int a,b;cin >> a >> b;
        g[a].pb(b);
    }

    for(int i = 1; i <= n; i++) ori = i, dfs(i);

    int a = 0, b = 0;
    int best = INF;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(sob[i][j] != INF) {
                if(sob[i][j] < best) {
                    best = sob[i][j];
                    a = i;
                    b = j;
                }
            }
        }
    }

    if(!a) { cout << -1 << endl; return 0; }
    vector<int> ans;
    while(a != b) { ans.pb(b); b = pai[a][b]; }
    ans.pb(a);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;

    return 0;
}
