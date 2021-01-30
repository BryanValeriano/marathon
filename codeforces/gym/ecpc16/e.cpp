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
vector<int> g[T];
int ans[T];
int n;

void bfs(int u) {
    for(int i = 1; i <= n; i++)
        ans[i] = INF;

    ans[u] = 0;
    queue<int> fila;
    fila.push(u);

    while(!fila.empty()) {
        u = fila.front();
        fila.pop();
        for(int v : g[u]) {
            if(ans[v]==INF) {
                ans[v] = ans[u]+1;
                fila.push(v);
            }
        }
    }
}

int main() {
    freopen("jumping.in","r",stdin);
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            if(i+x <= n) g[i+x].pb(i);
            if(i-x >= 1) g[i-x].pb(i);
        }
        bfs(n);
        for(int i = 1; i <= n; i++)
            cout << (ans[i]==INF?-1:ans[i]) << endl;
    }
    return 0;
}

