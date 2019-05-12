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
const ll INF = 0x3f3f3f3f3f3f;

const int T = 1e5 + 10;

ll v[T];
int n;
ll dp[T][2];

ll solve(int at, int impar) {
    if(at == n and impar) return 0;
    if(at == n) return -INF;
    if(dp[at][impar] != -1) return dp[at][impar];

    ll ans = solve(at+1, (impar + v[at]) & 1) + v[at];
    ans = max(ans, solve(at+1, impar));

    return dp[at][impar] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << solve(0,0) << endl;
    return 0;
}

