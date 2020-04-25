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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e3+2;

ll dp[T][T];
vii v;
int n;

ll solve(int l, int r) {
    if(l > r) return 0;
    if(~dp[l][r]) return dp[l][r];
    int x = l+n-r-1;
    return dp[l][r] = max(solve(l+1,r)+abs(v[x].se-l)*v[x].fi, solve(l,r-1)+abs(v[x].se-r)*v[x].fi);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.eb(x,i);
    }
    sort(v.begin(),v.end(),greater<ii>());
    cout << solve(0,n-1) << endl;
    return 0;
}

