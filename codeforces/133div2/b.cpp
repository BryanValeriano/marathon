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

const int T = 110;
vector<int> g[T];
int cycles;
int tin[T];
int tout[T];
int t,n;

void dfs(int u, int p, int nivel) {
    tin[u] = ++t;
    for(auto v : g[u]) {
        if(tin[v] and tout[v] == 0 and v != p) if(nivel&1) cycles++;
        if(!tin[v]) dfs(v,u,nivel+1);
    }
    tout[u] = t;
}

 
int main() {
    ios_base::sync_with_stdio(false);
    int m,x,y;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    for(int i = 1; i <= n; i++) 
        if(!tin[i]) dfs(i,i,1);
    
    if((n - cycles)&1) cycles++;
    cout << cycles << endl;
    
    return 0;
}

