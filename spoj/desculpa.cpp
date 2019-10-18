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

const int T = 1e3 + 5;

int dp[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,cont;
    cont = 0;
    cin >> n >> m;
    while(n or m) {
        cout << "Teste " << ++cont << endl;

        for(int i = 0; i <= n; i++) dp[i] = -INF;
        dp[0] = 0;
        int ans = 0;

        for(int i = 0; i < m; i++) {
            int x,v; cin >> x >> v;
            for(int j = n; j-x >= 0; j--) {
                dp[j] = max(dp[j], dp[j-x]+v);
                ans = max(ans,dp[j]);
            }
        }

        cout << ans << endl << endl;
        cin >> n >> m;
    }

    return 0;
}

