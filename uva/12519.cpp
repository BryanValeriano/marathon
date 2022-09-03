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
const int T = 102;
ll adj[T][T];

void reset(int n) {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            adj[i][j] = -INF;
}

void floyd(int n) {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,b;
    cin >> n;
    while(n) {
        reset(n);
        cin >> b;
        while(b--) {
            int u,v,t;
            cin >> u >> v >> t;
            adj[u][v] = t;
            adj[v][u] = -t;
        }
        floyd(n);
        bool ok = 0;
        for(int i = 1; i <= n; i++) ok |= (adj[i][i] != 0 && adj[i][i] != -INF);
        cout << (ok? 'Y' : 'N') << endl;
        cin >> n;
    }
    return 0;
}

