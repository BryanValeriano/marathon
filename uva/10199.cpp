#include <bits/stdc++.h>
using namespace std;

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
const int T = 102;
string volta[T];
map<string,int> id;
vector<int> g[T];
vector<string> ans;
int d[T], low[T];
int t;

void dfs(int u, int pai) {
    d[u] = low[u] = ++t;
    bool any = false;
    int nf = 0;
    for(int v : g[u]) {
        if(v == pai) continue;
        if(!low[v]) {
            dfs(v,u); nf++;
            if(low[v] >= d[u]) any = true;
            low[u] = min(low[u],low[v]);
        } else low[u] = min(low[u],d[v]);
    }
    if(u==pai and nf >= 2) ans.pb(volta[u]);
    else if(u != pai and any) ans.pb(volta[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int cont = 0;

    while(n) {
        ans.clear();
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            id[s] = i;
            volta[i] = s;
            g[i].clear();
            low[i] = d[i] = 0;
        }

        int m; cin >> m;
        while(m--) {
            string s,t; cin >> s >> t;
            g[id[s]].pb(id[t]);
            g[id[t]].pb(id[s]);
        }

        for(int i = 0; i < n; i++)
            if(!low[i])
                dfs(i,i);

        cout << "City map #" << ++cont << ": " << ans.size() << " camera(s) found\n";
        sort(ans.begin(),ans.end());
        for(string s : ans) cout << s << endl;
        cin >> n;
        if(n) cout << endl;
    }

    return 0;
}

