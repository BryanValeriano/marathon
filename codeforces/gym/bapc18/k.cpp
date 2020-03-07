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
const int T = 1e5 + 2;

int n,k,corn = -1;
int fat[T];
bool leaf[T];
bool vis[T];
vector<int> g[T];
vii ans;

void dfs(int u, int pai) {
    for(int v : g[u]) {
        if(v == pai) continue;
        fat[v] = u;
        dfs(v,u);
    }
    if(g[u].size() == 1) leaf[u] = 1;
}

void dfs2(int u, int pai, vector<int> &tmp) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(v == pai or v == k or v == corn) continue;
        dfs2(v,u,tmp);
    }
    if(leaf[u]) tmp.pb(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(k,k);

    vector<int> livres;

    for(int i = 0; i < n; i++) {
        if(i == k or vis[i]) continue;
        vector<int> tmp;
        dfs2(i,i,tmp);


        while((!livres.empty()) and (!tmp.empty())) {
            int x = livres.back();
            livres.pop_back();
            int y = tmp.back();
            tmp.pop_back();
            ans.eb(x,y);
        }

        livres.insert(livres.end(),tmp.begin(),tmp.end());
    }

    
    int last = -1;

    while(livres.size() > 1) {
        int x = livres.back();
        livres.pop_back();
        int y = livres.back();
        livres.pop_back();
        ans.eb(x,y);
        last = y;
    }

    if(livres.size()) last = livres.back();
    if(last != -1) ans.eb(last,k);

    cout << ans.size() << endl;
    for(auto x : ans) cout << x.fi << " " << x.se << endl;
    
    return 0;
}

