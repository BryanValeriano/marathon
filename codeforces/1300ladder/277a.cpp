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
const int T = 100 + 2;
bool vis[T];
vector<int>grups[T];
vector<int>know[T];
vector<int>g[T];

void dfs(int atual) {
    if(vis[atual]) return;
    else vis[atual] = true;
    for(int i = 0; i < g[atual].size(); i++) 
        dfs(g[atual][i]);
}

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int aux;
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        if(k) flag = false;
        for(int j = 0; j < k; j++) {
            cin >> aux;
            grups[aux].pb(i);
            know[i].pb(aux);
        }
    }
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j < know[i].size(); j++)
            for(int k = 0; k < grups[know[i][j]].size(); k++) 
                g[i].pb(grups[know[i][j]][k]);

    int ans = 0;
    for(int i = 1; i <= n; i++) if(!vis[i]) { ans++; dfs(i); } 
    if(flag) ans++; 
    cout << ans-1 << endl;
    return 0;
}

