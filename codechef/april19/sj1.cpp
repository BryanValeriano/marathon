#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
vector<int> g[T];
set<int> leaf;
int mdc[T];
int vis[T];
int val[T];
int mod[T];
int vez;

void dfs(int u, int gcd) {
    vis[u] = vez; 
    gcd = __gcd(gcd, val[u]);
    mdc[u] = gcd;

    bool l = false;

    for(auto v : g[u])
        if(vis[v] != vez) dfs(v, gcd), l = true;

    if(!l) leaf.insert(u);
}

void init() {
    for(int i = 0; i < T; i++) g[i].clear();
    leaf.clear();
}

int32_t main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        init();
        int n,x,y; cin >> n;

        for(int i = 0; i < n-1; i++) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        for(int i = 1; i <= n; i++) cin >> val[i];
        for(int i = 1; i <= n; i++) cin >> mod[i];
        
        vez++;
        dfs(1,0);

        for(auto z : leaf) {
            int gcd = __gcd(mdc[z], mod[z]);
            cout << mod[z] - gcd << " ";
        }

        cout << endl;
    }

    return 0;
}

