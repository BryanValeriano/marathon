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

const int T = 502;
vector<int> g[T];
vector<int> edg;
bool del[T*T];

int vis[T];
int tout[T];
int n,m,v;

vector<int> used;
vector<int> cycle;
bool flag;

bool dfs(int at) {
    vis[at] = v;
    tout[at] = -1;

    bool ans = false;

    for(int a : g[at]) {
        if(ans) {tout[at] = 1; return true; }
        if(del[a]) continue;

        int nxt = edg[a];
        if(tout[nxt] == -1) {tout[at] = 1; return true; }
        if(vis[nxt] != v) ans |= dfs(nxt);
    }

    tout[at] = 1;
    return ans;
}

void build() {
    cycle = used; 
}

void dfs2(int at) {
    if(flag) return;
    vis[at] = v;
    tout[at] = -1;

    for(int a : g[at]) {
        if(flag) return;

        int nxt = edg[a];
        used.pb(a);

        if(tout[nxt] == -1) {
            flag = 1;
            build();
            return;
        }

        if(vis[nxt] != v) dfs2(nxt);
        used.pop_back();
    }
    
    tout[at] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a,b;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].pb(edg.size());
        edg.pb(b);
    }

    ++v;
    for(int i = 1; i <= n; i++) 
        if(vis[i] != v and !flag) 
            dfs2(i);

    memset(tout, 0, sizeof tout);
    if(!cycle.size()) { cout << "YES" << endl; return 0; }

    for(int i = 0; i < cycle.size(); i++) {
        if(i > 0) del[cycle[i-1]] = 0;
        del[cycle[i]] = 1;

        bool ans = 0;
        ++v;

        for(int j = 1; j <= n; j++) {
            if(ans) break;
            if(vis[j] != v) ans |= dfs(j);
        }

        if(!ans) { cout << "YES" << endl; return 0; }
    }

    cout << "NO" << endl;

    return 0;
}

