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

const ll MOD = 1e9+7;
const int T = 2e3 + 3;

vector<int> g[T];
bool vis[T];

void dfs(int at) {
    vis[at] = 1;
    for(int v : g[at])
        if(!vis[v]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m,k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        if(i+k-1 <= n) {
            int l = i;
            int r = i+k-1;
            while(l < r) {
                g[l].pb(r);
                g[r].pb(l);
                r--, l++;
            }
        }
    }

    ll ans = 1;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans = (ans * m) % MOD, dfs(i);
        }
    }

    cout << ans << endl;
    return 0;
}

