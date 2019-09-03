#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< pair<int,int> >pii;
const int INF = 0x3f3f3f3f;
const int T = 1000 + 3;
int source, n;
pii row[T];
int vis = 0;
int visit[T];

int dfs(int atual, int cost) {
    if(visit[atual] == vis) return 0;
    visit[atual] = vis;
    int sum = 0;
    for(int i = 0; i < row[atual].size(); i++) 
        sum += dfs(row[atual][i].fi, row[atual][i].se);
    if(sum == 0) sum = INF;
    return min(cost, sum);
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> n) {
        ++vis;
        cin >> source;
        int u, v, c;
        for(int i = 0; i < n-1; i++) {
            cin >> u >> v >> c;
            row[u].pb(mp(v, c));
            row[v].pb(mp(u, c));
        }
        cout << dfs(source, INF) << endl;
        for(int i = 1; i <= n; i++) 
            row[i].clear();
    }
    return 0;
}

