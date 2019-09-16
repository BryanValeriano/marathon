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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e3 + 3;
ll ok[T];
ll v[T][T];
ll dp[T][T];
int n;
ll d,c;

ll solve(int at, int last) {
    if(at == n) return d + (v[last][at])*c;
    if(dp[at][last] != -1) return dp[last][at];
    ll ans = INF;
    ans = min(ans, solve(at+1, last));
    ans = min(ans, solve(at+1, at+1) + d + (v[last][at])*c);
    return dp[at][last] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> d >> c;
    for(int i = 1; i <= n; i++) cin >> ok[i];

    for(int i = n; i >= 1; i--)
        for(int j = i; j <= n; j++)
            v[i][j] = ok[j] - ok[i], v[i][j] += v[i+1][j];

    cout << solve(1,1) << endl;
    return 0;
}

