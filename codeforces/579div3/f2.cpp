#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 102;
const int N = 6e4 + 2;

vii pos;
vii neg;
int dp[T][N];

bool cmp(const ii &a, const ii &b) {
    return a.fi - b.se > b.fi - a.se;
}

int solve(int at, int r) {
    if(at == neg.size()) return 0;
    if(dp[at][r] != -1) return dp[at][r];

    dp[at][r] = solve(at+1,r);
    if(r+neg[at].se >= 0 and r >= neg[at].fi)
        dp[at][r] = max(dp[at][r], solve(at+1,r+neg[at].se)+1);

    return dp[at][r];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    int n,r; cin >> n >> r;

    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        if(y >= 0) pos.eb(x,y);
        else neg.eb(max(x,-y),y);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), cmp);

    int ans = 0;

    for(int i = 0; i < pos.size(); i++) {
        if(r < pos[i].fi) break;
        r += pos[i].se;
        ans++;
    }

    cout << ans+solve(0,r) << endl;

    return 0;
}
