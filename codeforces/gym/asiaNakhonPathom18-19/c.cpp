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

int n;
int w;
const int T = 5e3 + 3;
int v[T];
int ok[T];
bool vis[T];
int ans;
vector<int> g[T];

void dfs(int u) {
    vis[u] = 1;
    ok[u] = 0;
    for(int nxt : g[u]) {
        if(!vis[nxt]) dfs(nxt);
        ok[u] = max(ok[u], ok[nxt]+1);
    }
    ans = max(ans,ok[u]);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> w;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        for(int j = i-1; j >= 0 and j >= i-w; j--) {
            if(v[i] > v[j]) g[j].pb(i);
            else if(v[j] > v[i]) g[i].pb(j);
        }
    }
    
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
    
    cout << ans << endl; 
    return 0;
}

