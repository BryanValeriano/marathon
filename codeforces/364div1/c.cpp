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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+2;
int aux[2];
int vis[T], pai[T], peso[T], d[T], low[T];
vector<ti> e;
vector<int> pontes;
int s,t,p=-1,vez,temp;

void init(vector<vector<int>> &g) {
    for(int i = 0; i < T; i++) {
        g[i].clear();
        pai[i] = i;
        peso[i] = 1;
        d[i] = low[i] = 0;
    }
    temp = 0;
}

int find(int x) {
    return (x==pai[x]?x:pai[x]=find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(peso[y] > peso[x]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

void lowLink(int u, int z, vector<vector<int>> &g) {
    d[u] = low[u] = ++temp;
    for(int ee : g[u]) {
        if(ee == p) continue;
        auto [x,y,w] = e[ee];
        int v = (x==u?y:x);
        if(!low[v] and ee != z) {
            lowLink(v,ee,g);
            if(low[v] > d[u]) pontes.pb(ee);
            else join(u,v);
            low[u] = min(low[v],low[u]);
            //cout << u << " -> " << v << " = " << (low[v] > d[u]) << endl;
        } else if(ee != z) low[u] = min(low[u],d[v]);
    }
}

ii dfs(int u, vector<vector<int>> &g) {
    ii ans = mk(INF,INF);
    vis[u] = vez;

    for(int ee : g[u]) {
        if(ee == p) continue;
        auto [x,y,w] = e[ee];
        x = find(x);
        y = find(y);
        int v = (x==u?y:x);
        if(vis[v] != vez) {
            ii tmp = dfs(v,g);
            if(v == find(t) or tmp.fi != INF)
                ans = min(tmp,mk(w,ee));
        }
    }

    return ans;
}

void cond(vector<vector<int>> &g, vector<vector<int>> &h) {
    pontes.clear();
    init(h);
    lowLink(s,-1,g);
    for(int ee : pontes) {
        if(ee == p) continue;
        //cout << "x " << ee+1 << endl;
        auto [x,y,w] = e[ee];
        x = find(x);
        y = find(y);
        //cout << find(s) << " " << find(t) << " | " << x << " " << y << endl;
        h[x].pb(ee);
        h[y].pb(ee);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    vector<vector<int>> g(T), h(T);
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

    init(h);
    vez++;
    int ans = dfs(s,g).fi;
    ans = (ans==INF?0:INF);
    int c = 0;

    for(p=0; p<e.size(); p++) {
        //cout << p+1 << " ---------------------\n";
        cond(g,h);
        vez++;
        ii tmp = dfs(find(s),h);
        if(find(s) == find(t)) continue;
        int w = get<2>(e[p]);
        if(tmp.fi == INF) tmp.fi = 0;
        if(ans > w+tmp.fi) {
            ans = w+tmp.fi;
            aux[0] = p;
            if(tmp.fi) aux[1] = tmp.se, c = 2;
            else c = 1;
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

