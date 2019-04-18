#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
ll dp[T];
vector<ii> v;
ll n;

ll solve(int at, int left, int right) {
    if(at == n) return 0;
    if(dp[at] != -1) return dp[at];

    ll ans = solve(at + 1, left + 1, right) +
        (v[at].fi * left) + (v[at].se * ((n-left-1)));

    ans = min(ans, solve(at+1, left, right + 1) +
        (v[at].se * right) + (v[at].fi * (n-right-1)));

    return dp[at] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int l,r;
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        v.eb(l,r);
    }
    
    sort(v.begin(), v.end(), [] (const ii &a, const ii &b) { return max(a.fi,a.se) > max(b.fi,b.se); });

    cout << solve(0,0,0) << endl;

    return 0;
}

