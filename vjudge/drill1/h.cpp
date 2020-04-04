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
const int T = 21;
const int K = 1003;

int dp[K];
int maxRat[T][K];

int c[T][T];
int p[T][T];
int n,m,k;

int solve() {
    dp[0] = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = k; j >= 0; j--)
            for(int z = j; z >= 0; z--) {
                dp[j] = max(dp[j], dp[j-z] + maxRat[i][z]);
                ans = max(ans,dp[j]);
            }

    return ans;
}

void pre(int i, int cost) {
    maxRat[i][cost] = 0;
    for(int j = 1; j <= m; j++)
        for(int z = cost+c[i][j]; z <= k; z++)
            maxRat[i][z] = max(maxRat[i][z], maxRat[i][z-c[i][j]]+p[i][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) cin >> c[i][0];

        for(int i = 0; i < n; i++)
            for(int j = 1; j <= m; j++)
                cin >> c[i][j];

        for(int i = 0; i < n; i++)
            for(int j = 1; j <= m; j++)
                cin >> p[i][j];

        memset(maxRat,-INF,sizeof maxRat);
        memset(dp,-INF,sizeof dp);
        for(int i = 0; i < n; i++) pre(i,c[i][0]);

        cout << solve() << endl;
    }
    return 0;
}

