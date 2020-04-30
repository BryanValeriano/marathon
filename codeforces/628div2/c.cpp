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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5;
bool vis[T];
bool vis2[T];
int ans[T];
vii g[T];

void bfs(int root) {
    queue<int> fila;
    fila.push(root);
    vis2[root] = 1;
    int ok = 0;
    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        vti tmp;
        for(ii v : g[u]) {
            if(vis[v.se]) continue;
            tmp.eb(g[v.fi].size(),v.se,v.fi);
        }
        sort(tmp.begin(),tmp.end(),greater<ti>());
        for(ti nxt : tmp) {
            int d,e,v;
            tie(d,e,v) = nxt;
            if(!vis[e]) ans[e] = ok++;
            vis[e] = 1;
            if(!vis2[v]) fila.push(v);
            vis2[v] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].eb(b,i);
        g[b].eb(a,i);
    }

    int best = 0;
    int root = 0;

    for(int i = 1; i <= n; i++)
        if(best < g[i].size()) best = g[i].size(), root = i;

    bfs(root);
    for(int i = 0; i < n-1; i++) cout << ans[i] << endl;

    return 0;
}

