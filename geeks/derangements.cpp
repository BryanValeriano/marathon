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

const int T = 1e5 + 10;
const int MOD = 1e9 + 7;

ll dp[T];

ll der(ll x) {
    if(dp[x] != -1) return dp[x];
    if(x == 1) return 0;
    if(x == 0) return 1;

    return dp[x] = ((x-1) * ((der(x-1) + der(x-2)) % MOD) ) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        cout << der(n) << endl;
    }
    return 0;
}

