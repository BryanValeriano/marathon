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
const int T = 2e5 + 5;

int m,n,k,t;
int a[T];
int need[T];

vector<ii> v[T];
ll dp[2][2];

void pre(int agi) {
    for(ll i = 0; i <= n; i++) {
        ll maxr = i;

        for(auto trap : v[i+1])
            if(trap.fi > agi) maxr = max(maxr,(ll)trap.se);

        need[i] = maxr;
    }
}

ll solve() {
    bool ok = 0;
    memset(dp, 0, sizeof dp);

    ll safe = 0;
    for(ll i = 0; i <= n; i++) {
        ll desarm = need[i];
        safe = max(safe,i);

        if(safe >= desarm) desarm = safe;

        dp[ok][1] = min(dp[!ok][0]+2*max(desarm,safe), dp[!ok][1]) + (desarm-safe)*2+1;
        dp[ok][0] = dp[!ok][0]+1;

        //cout << desarm << " " << safe << endl;
        //cout << i << " " << dp[ok][1] << " " << dp[ok][0] << endl;

        ok = !ok;
        safe = max(safe,desarm);
    }

    return dp[!ok][1];
}

bool check(int agi) {
    pre(agi);
    //cout << agi << " " << solve() << endl;
    return (solve() <= t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> k >> t;
    for(int i = 0; i < m; i++) cin >> a[i];

    while(k--) {
        int l,r,d;
        cin >> l >> r >> d;
        v[l].eb(d,r);
    }

    int l = 0;
    int r = 2e5 + 10;

    int maxi = INF, ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) maxi = mid, r = mid-1;
        else l = mid+1;
    }

    //check(3);

    for(int i = 0; i < m; i++) ans += (maxi <= a[i]);
    cout << ans << endl;

    return 0;
}

