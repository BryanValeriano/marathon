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
const int T = 1e3 + 2;
vii g[T];
vii ans[T];
int in[T];
int vis[T];
int n,p;

void dfs(int at, int d, vii &v) {
    vis[at] = 1;
    for(ii nxt : g[at]) {
        if(vis[nxt.fi]&1) continue;
        dfs(nxt.fi,min(d,nxt.se),v);
    }
    vis[at] = 2;
    if(!g[at].size()) v.eb(at,d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> p;

    for(int i = 0; i < p; i++) {
        int a,b,d; cin >> a >> b >> d;
        g[a].eb(b,d);
        in[b]++;
    }

    int t = 0;

    for(int i = 1; i <= n; i++) {
        if(!in[i] and g[i].size()) {
            dfs(i,INF,ans[i]);
            t += ans[i].size();
        }
    }

    cout << t << endl;

    for(int i = 1; i <= n; i++)
        if(!in[i])
            for(auto x : ans[i]) cout << i << " " << x.fi << " " << x.se << endl;

    return 0;
}

