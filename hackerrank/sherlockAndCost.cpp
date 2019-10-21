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

ll dp[2][4];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    ll x, last;
    while(tc--) {
        int n; cin >> n;
        cin >> last;
        memset(dp,0,sizeof dp);
        n--;
        while(n--) {
            cin >> x;
            //0 0
            dp[1][0] = max(dp[0][0] + (1-1), dp[0][2] + (1-1));
            //0 1
            dp[1][1] = max(dp[0][0] + x-1, dp[0][2] + x-1);
            //1 0
            dp[1][2] = max(dp[0][1] + last-1, dp[0][3] + last-1);
            //1 1
            dp[1][3] = max(dp[0][1] + abs(last-x), dp[0][3] + abs(last-x));
            for(int i = 0; i < 4; i++) dp[0][i] = dp[1][i];
            last = x;
        }
        cout << max({dp[0][0],dp[0][1],dp[0][2],dp[0][3]}) << endl;
    }

    return 0;
}

