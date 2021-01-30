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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 502;
ll v[T];
ll dp[T][T];
bool ok[T][T];

void solve(int n) {

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            dp[i][j] = LLONG_MAX;
            ok[i][j] = 0;
        }

    dp[0][0] = 0;
    ok[0][0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            for(int k = 1; k <= j; k++)
                if(ok[i-1][j-k]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-k] + v[k]);
                    ok[i][j] = 1;
                }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("jacking.in","r",stdin);
    int t; cin >> t;
    int cont = 0;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> v[i];
        int q; cin >> q;
        cout << "Case " << ++cont << ": " << endl;
        solve(n);
        while(q--) {
            int t,m; cin >> t >> m;
            if(t >= m) cout << dp[m][t] << endl;
            else cout << "impossible\n";
        }
    }
    return 0;
}

