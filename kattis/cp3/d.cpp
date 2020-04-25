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
const int T = 5e3 + 2;

int wid[T], hi[T], dp[T];
int maxH[T][T], sumW[T][T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,W; cin >> n >> W;
    for(int i = 1; i <= n; i++) cin >> wid[i] >> hi[i];

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            sumW[i][j] = wid[j] + sumW[i][j-1];
            maxH[i][j] = max(maxH[i][j-1], hi[j]);
        }
    }


    memset(dp,INF,sizeof dp);
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if(sumW[i][j] <= W) dp[j] = min(dp[j], dp[i-1]+maxH[i][j]);

    cout << dp[n] << endl;

    return 0;
}

