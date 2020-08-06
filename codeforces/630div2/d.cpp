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
const int T = 502;
int a[T][T], dp[T][T];
int n,m;

int solve1() {
    memset(dp,0,sizeof dp);
    dp[0][1] = a[1][1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i-1][j]&a[i][j],dp[i][j-1]&a[i][j]);
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    cout << solve1() << endl;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}

