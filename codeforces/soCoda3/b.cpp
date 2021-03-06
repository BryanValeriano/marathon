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
const int T = 2e3 + 2;
const ll MOD = 1e9+7;

int d[T];
vector<int> g[T];
int dist;
int s;

ll dfs(int a, int pai) {
    ll ans = 1;

    for(int v : g[a]) {
        if(v == pai) continue;
        if(d[v] == d[s] and v < s) continue;
        if(d[v] >= d[s] and d[v] - d[s] <= dist)
            ans = (ans * (dfs(v,a)+1)) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> dist >> n;
    for(int i = 1; i <= n; i++) cin >> d[i];

    for(int i = 0; i < n-1; i++) {
        int a,b;cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ll ans = 0;

    for(s = 1; s <= n; s++) {
        ans = (ans + dfs(s,s)) % MOD;
    }

    cout << ans << endl;

    return 0;
}

