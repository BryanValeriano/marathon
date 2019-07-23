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

const int T = 62;

string s;
int n;
ll dp[T][T];

ll solve() {
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) {
        for(int j = 0; i + j < n; j++) {
            if(i == 0) dp[j][j] = 1;
            else if(s[j] == s[i+j]) dp[j][i+j] = dp[j+1][i+j] + dp[j][i+j-1] + 1;
            else dp[j][i+j] = dp[j+1][i+j] + dp[j][i+j-1] - dp[j+1][i+j-1];
        }
    }
    
    return dp[0][n-1];
}

int main() {
    ios::sync_with_stdio(false);

    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        n = s.size();
        cout << solve() << endl;
    }

    return 0;
}

