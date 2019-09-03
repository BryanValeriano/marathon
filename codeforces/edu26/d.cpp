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

const int T = 5*26*202;

int dp[205][5250];

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;

    int n, k, c, d; 
    ll x;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        ll y = x;
        c = d = 0;

        while(y % 2 == 0) y /= 2, d++;
        y = x;
        while(y % 5 == 0) y /= 5, c++;

        for(int j = i; j >= 1; j--) {
            for(int s = 5249; s - c >= 0; s--) {
                if(dp[j-1][s - c] == -1) continue;
                dp[j][s] = max(dp[j][s], dp[j-1][s-c] + d);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 5250; i++) ans = max(ans,min(dp[k][i],i));
    cout << ans << endl;

    return 0;
}

