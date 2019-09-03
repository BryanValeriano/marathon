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
const int T = 105;
bitset<T> cols;
bitset<T> vis;
vector<int> g[T];
vector<int> resp;
int ans;
int n, m;

void solve(int atual) {
    if(atual > n) {
        int qtd = 0;
        for(int i = 1; i <= n; i++) 
            if(cols[i] == true)
                qtd++;
        if(qtd > ans) {
            ans = qtd;
            resp.clear();
            for(int i = 1; i <= n; i++) 
                if(cols[i] == true)
                    resp.pb(i);
        }
        return;
    }
    bool podeBlack = true;
    for(int i = 0; i < g[atual].size(); i++) {
        int vizinho = g[atual][i];
        if(vis[vizinho] == true and cols[vizinho] == true) {
            podeBlack = false;
            break;
        }
    }
    vis[atual] = true;
    if(podeBlack) {
        cols[atual] = true;
        solve(atual+1);
    }
    cols[atual] = false;
    solve(atual+1);
}

void init() {
    ans = 0;
    resp.clear();
    cols.reset();
    vis.reset();
    for(int i = 1; i <= n; i++)
        g[i].clear();
}

void read() {
    int u, v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        init();
        read();
        solve(1);
        cout << ans << endl;
        for(int i = 0; i < resp.size() -1; i++)
            cout << resp[i] << " ";
        cout << *resp.rbegin() << endl;
    }
    return 0;
}

