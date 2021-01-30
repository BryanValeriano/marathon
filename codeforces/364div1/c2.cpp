#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ii> vii;
const int INF = INT_MAX;
const double PI = acos(-1.0);
const int T = 1e3+2;

int aux[2];
int d[T], low[T];
vector<int> g[T];
bool ok[T];
vector<ti> e;
int s,t,p=-1,vez,temp;
ii tmp;

void init() {
    for(int i = 0; i < T; i++)
        d[i] = low[i] = ok[i] = 0;
    temp = 0;
}

void lowLink(int u, int z) {
    d[u] = low[u] = ++temp;
    for(int ee : g[u]) {
        if(ee == p) continue;
        auto [x,y,w] = e[ee];
        int v = (x==u?y:x);
        if(!low[v] and ee != z) {
            lowLink(v,ee);
            if(low[v] > d[u] and d[v] <= d[t]) tmp = min(tmp,mk(w,ee));
            low[u] = min(low[v],low[u]);
        } else if(ee != z) low[u] = min(low[u],d[v]);
    }
}

void dfs(int u) {
    ok[u] = 1;
    if(u==s) return;
    for(int ee : g[u]) {
        if(ee == p) continue;
        auto [x,y,w] = e[ee];
        int v = (x==u?y:x);
        if(!ok[v]) dfs(v);
    }
}

bool dfs2(int u, vector<int> &st) {
    if(u == t) return 1;
    low[u] = 1;

    for(int ee : g[u]) {
        auto [x,y,w] = e[ee];
        int v = (x==u?y:x);
        if(low[v]) continue;
        st.pb(ee);
        if(dfs2(v,st)) return 1;
        st.pop_back();
    }

    return 0;
}

vector<int> getPath(int u) {
    vector<int> ans;
    dfs2(u,ans);
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    cin >> s >> t;
    if(s==t) {
        cout << -1 << endl;
        return 0;
    }
    while(m--) {
        int x,y,w; cin >> x >> y >> w;
        g[x].pb(e.size());
        g[y].pb(e.size());
        e.eb(x,y,w);
    }

    dfs(t);
    int ans = INF, c = 0;
    if(!ok[s]) ans = 0;
    vector<int> path = getPath(s);

    for(int i = 0; i < path.size(); i++) {
        p = path[i];
        //cout << p+1 << " ---------------------\n";
        init();
        int w = get<2>(e[p]);
        if(w >= ans) continue;
        dfs(t);
        if(!ok[s] and w < ans) {
            ans = w;
            c = 1;
            aux[0] = p;
        } else {
            tmp = mk(INF,INF);
            lowLink(s,-1);
            if(ans > w+tmp.fi) {
                ans = w+tmp.fi;
                aux[0] = p;
                aux[1] = tmp.se;
                c = 2;
            }
        }
        //cout << p+1 << " xxxxxxxxxxxxxxxxxxx\n";
    }

    if(ans==INF) cout << -1 << endl;
    else {
        cout << ans << endl;
        cout << c << endl;
        for(int i = 0; i < c; i++) cout << aux[i]+1 << " ";
        cout << endl;
    }

    return 0;
}
