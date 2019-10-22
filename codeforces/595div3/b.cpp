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

const int T = 2e5 + 4;
int st[T];
int ed[T];
int vis[T];
vector<int> g[T];
int vez;
int n;

void dfs(int u, int d) {
    if(vis[u] == vez) {
        ed[u] = d;
        vis[u] = vez+1;
    } else if(vis[u] < vez) {
        vis[u] = vez;
        st[u] = d;
    } else return;

    for(int v : g[u])
        dfs(v,d+1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            g[i].clear();
            g[i].pb(x);
        }
        vez += 5;
        for(int i = 1; i <= n; i++) {
            if(vis[i] < vez) dfs(i,0);
            cout << ed[i] - st[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

