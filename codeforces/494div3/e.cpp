#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 4e5 + 40;
vii edgs;
vector<int> g[T];
int dist[T];

ii dfs(int u, int pai, int niv) {
    ii ans = mk(niv,u);
    for(int v : g[u]) {
        if(v == pai) continue;
        ans = max(ans, dfs(v,u,niv+1));
    }
    return ans;
}

int diametro() {
    ii x = dfs(1,1,0);
    ii y = dfs(x.se,x.se,0);
    return y.fi;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,d,k;
    cin >> n >> d >> k;
    if(d > n) {
        cout << "NO" << endl;
        return 0;
    }


    vector<int> bank;
    bank.pb(1);
    dist[1] = d-1;
    for(int i = 2; i <= d; i++) {
        g[i-1].pb(i);
        g[i].pb(i-1);
        edgs.eb(i-1,i);
        dist[i] = max(i-1,d-i);
        bank.pb(i);
    }

    if(d>1)bank.pop_back();
    int ok = d+1;

    while(edgs.size() < n-1 and bank.size()) {
        vector<int> tmp;
        for(auto u : bank) {
            while(g[u].size() < k and ok <= n) {
                if(dist[u] == d) break;
                tmp.pb(ok);
                edgs.eb(u,ok);
                g[u].pb(ok);
                dist[ok] = dist[u]+1;
                g[ok++].pb(u);
            }
        }
        bank = tmp;
    }

    //for(auto x : edgs) cout << x.fi << " " << x.se << endl;

    if(edgs.size() < n-1) {
        cout << "NO" << endl;
        return 0;
    }

    if(diametro() == d) {
        cout << "YES" << endl;
        for(auto x : edgs) cout << x.fi << " " << x.se << endl;
    } else cout << "NO" << endl;


    return 0;
}

