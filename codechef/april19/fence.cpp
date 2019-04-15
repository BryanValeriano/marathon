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

map<ii, vector<ii> > g;
set<ii> vis;
set<ii> exist;
vector<ii> v;
ll ans = 0;
int n,m;

int mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

bool isIn(int x, int y) {
    return (x >= 1 and x <= n and y >= 1 and y <= m);
}

void explode(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int xx = x + mov[i][0];
        int yy = y + mov[i][1];
        if(isIn(xx,yy)) g[mk(x,y)].pb({xx,yy});
    }
}

void dfs(int x, int y) {
    ii u = mk(x,y);
    vis.insert(u);
    for(auto z : g[u]) {
        if(exist.count(z) and !vis.count(z)) { 
            dfs(z.fi,z.se);
            ans--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc,k,x,y; cin >> tc;

    while(tc--) {
        cin >> n >> m >> k;
        g.clear(); v.clear();
        vis.clear(); exist.clear();
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            v.pb({x,y});
            exist.insert(mk(x,y));
            explode(x,y);
        }

        ans = 4*k;

        for(int i = 0; i < k; i++) 
            if(!vis.count(mk(v[i].fi,v[i].se))) 
                dfs(v[i].fi, v[i].se);

        cout << ans << endl;
    }

    return 0;
}

