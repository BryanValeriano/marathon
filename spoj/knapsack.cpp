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

const int T = 2e3 + 3;
int dp[T];

int main() {
    ios_base::sync_with_stdio(false);
    int c,n; cin >> c >> n;
    for(int i = 0; i <= c; i++) dp[i] = -INF;

    dp[0] = 0;
    int ans = 0;

    while(n--) {
        int w,v; cin >> w >> v;
        for(int i = c; i-w >= 0; i--) {
            dp[i] = max(dp[i], dp[i-w] + v);
            ans = max(ans,dp[i]);
        }
    }

    cout << ans << endl;

    return 0;
}

