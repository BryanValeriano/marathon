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
const ll INF = 1e17;
const double PI = acos(-1.0);
const int T = 1e5 + 3;
ll dp[T][3];
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = -INF;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i][0] = 100ll*v[i];
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j < 3; j++) {
            if(j&1) dp[i][j] = max({dp[i][j], dp[i][j-1]-k, dp[i-1][j]-k});
            else {
                dp[i][j] = max(dp[i][j], dp[i][j-1]-100ll*v[i]);
                ans = max(ans,dp[i][j]);
            }
        }

    cout << ans << endl;

    return 0;
}

