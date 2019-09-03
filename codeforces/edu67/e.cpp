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

const int T = 2e5 + 5;
vector<int> g[T];
bool vis[T];
ll tot = 0;

ll dfs(int at) {
    vis[at] = 1;
    ll ans = 1;

    for(auto v : g[at]) 
        if(!vis[v]) ans += dfs(v);

    cout << at << " " << ans << endl;
    tot += ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a,b;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int ini;
    for(int i = 1; i <= n; i++) if(g[i].size() == 1) ini = i;
    cout << endl;
    
    dfs(ini);

    cout << tot << endl;

    return 0;
}

