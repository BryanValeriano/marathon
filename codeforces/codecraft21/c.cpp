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
const ll MOD = 1e9+7;
const int T = 1e3+5;
ll dp[2][T][T];

void reset(int n, int k) {
    for(int p = 0; p < 2; p++)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= k; j++)
                dp[p][i][j] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,k;
        cin >> n >> k;
        reset(n,k);
        dp[0][0][k] = 1;

        if(k == 1) {
            cout << 1 << endl;
            continue;
        }

        ll ans = 0;
        for(int i = k; i >= 1; i--) {
            //lado = 1 -> volta
            //lado = 0 -> ida
            int lado = (k-i)&1;
            if(!lado) {
                for(int j = 0; j < n; j++) {
                    if(j) dp[lado][j][i] = (dp[lado][j][i] + dp[lado][j-1][i]) %MOD;
                    if(i) dp[!lado][j][i-1] = dp[lado][j][i];
                }
                ans = (ans + dp[lado][n-1][i]) % MOD;
                //cout << i << " " << dp[lado][n-1][i] << endl;
            } else {
                for(int j = n-1; j >= 0; j--) {
                    if(j < n-1) dp[lado][j][i] = (dp[lado][j][i] + dp[lado][j+1][i]) % MOD;
                    if(i && j) dp[!lado][j][i-1] = dp[lado][j][i];
                }
                ans = (ans + dp[lado][0][i]) % MOD;
                //cout << i << " " << dp[lado][0][i] << endl;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

