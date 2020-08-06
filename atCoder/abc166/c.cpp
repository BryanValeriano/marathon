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
const int T = 1e5 + 3;
int h[T];
vector<int> g[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <=n;i++) cin >> h[i];

    while(m--) {
        int x,y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        bool ok = 1;
        for(int v : g[i]) ok &= (h[i]>h[v]);
        ans += ok;
    }

    cout << ans << endl;

    return 0;
}

