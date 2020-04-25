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
const int N = 102;
const int T = 1400;
int dp[N][N][T];
int d[N][N], t[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,m;
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x; cin >> x;
                d[i][j] = t[i][j] = 0;
                while(x%2==0) d[i][j]++, x /= 2;
                while(x%3==0) t[i][j]++, x /= 3;
                for(int k = 0; k < T; k++) dp[i][j][k] = -INF;
                dp[i][j][t[i][j]] = d[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = T-1; k-t[i][j] >= 0; k--) {
                    if(i-1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-t[i][j]] + d[i][j]);
                    if(j-1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-t[i][j]] + d[i][j]);
                    if(i==n-1 and j ==m-1) ans = max(ans,min(k,dp[i][j][k]));
                }

        cout << ans << endl;
    }

    return 0;
}

