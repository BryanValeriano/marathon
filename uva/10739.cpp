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

const int T = 1002;

string s;
int dp[T][T];
int n;

int solve() {
    memset(dp,INF,sizeof dp);
    for(int i = 0; i < n; i++) dp[i][i] = 0, dp[i][i+1] = (s[i] != s[i+1]);

    int ans = INF;

    for(int i = 2; i < n; i++)
        for(int j = 0; i+j < n; j++) {
            dp[j][j+i] = min(dp[j][j+i], dp[j+1][j+i-1] + (s[j] != s[j+i]));
            dp[j][j+i] = min(dp[j][j+i], dp[j][j+i-1] + 1);
            dp[j][j+i] = min(dp[j][j+i], dp[j+1][j+i] + 1);
            ans = min(ans, dp[j][j+i] + (n-i-1));
        }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        cin >> s;
        n = s.size();
        cout << "Case " << ++cont << ": " << solve() << endl;
    }

    return 0;
}

