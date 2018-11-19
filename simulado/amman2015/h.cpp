#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 1e6 + 5;
int visit[T];
int vis = 0;
vector<int> g[T];

void dfs(int atual) {
    if(visit[atual] == vis) return;
    visit[atual] = vis;
    for(int i = 0; i < g[atual].size(); i++) 
        dfs(g[atual][i]);
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        vis++;
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            g[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        int cp = 0;
        for(int i = 1; i <= n; i++) {
            if(visit[i] != vis) {
                cp++;
                dfs(i);
            }
        }
        cout << (cp == 1? 0: cp - 1) << endl;
    }        

    return 0;
}

