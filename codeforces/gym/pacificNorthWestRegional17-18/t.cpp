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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e3 + 3;

struct edge { int b, c, d; };
vector<edge> g[T];
vector<int> v;
int vis[T];
int n,m,k,s,t;
int val, vez;

bool dfs(int u) {
    if(u == t) return 1;
    vis[u] = vez;
    bool ans = 0;

    for(edge e : g[u])
        if(vis[e.b] != vez and val >= e.c and val <= e.d)
            ans |= dfs(e.b);

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> s >> t;
    int a,b,c,d;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        v.pb(c), v.pb(d+1);
        edge e = { b, c, d };
        g[a].pb(e);
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int ans = 0;

    for(int i = 0; i < v.size(); i++) {
        val = v[i];
        int nxt = (i+1 < v.size()? v[i+1] : k+1);
        vez++;
        if(dfs(s)) ans += (nxt-val);
    }

    cout << ans << endl;

    return 0;
}

