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
typedef tuple<bool,int,int> ti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+2;
vector<int> down[T];
int up[T];
bool need[T];

ii dfs(int u) {
    ii ans = mk(0,0);
    for(int v : down[u]) {
        ii tmp = dfs(v);
        ans.fi += tmp.fi;
        ans.se = max(ans.se,tmp.se);
    }
    if(need[u] or ans.fi) ans = mk(up[u]+ans.fi,up[u]+ans.se);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,f;
    while(cin >> n) {
        cin >> f;
        for(int i = 1; i <= n; i++) {
            down[i].clear();
            need[i] = 0;
        }
        for(int i = 0; i < n-1; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            down[a].pb(b);
            up[b] = c;
        }
        for(int i = 0; i < f; i++) {
            int x; cin >> x;
            need[x] = 1;
        }
        ii ans = dfs(1);
        cout << ans.fi - ans.se << endl;
    }
    return 0;
}

