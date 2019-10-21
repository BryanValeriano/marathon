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

const int T = 5e3 + 3;
int dp[T][T];
string s;
int n;

int solve() {
    memset(dp, INF, sizeof dp);

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        dp[i+1][i] = 0;
        dp[i-1][i] = (s[i-1] != s[i]);
    }

    for(int i = 1; i <= n; i++) {
        for(int l = 1; l+i <= n; l++) {
            int r = l+i;
            dp[l][r] = min({dp[l][r], dp[l+1][r]+1, dp[l][r-1]+1});
            if(s[l] == s[r]) dp[l][r] = min(dp[l][r],dp[l+1][r-1]);
        }
    }

    return dp[1][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    s = '#' + s;
    cout << solve() << endl;
    return 0;
}

