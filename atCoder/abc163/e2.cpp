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
const int T = 2e3+3;
ll dp[T][T];
vii v;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.eb(x,i+1);
    }

    sort(v.begin(),v.end());
    ll ans = 0;

    for(int i = n-1; i >= 0; i--)
        for(int j = 1; j+i <= n; j++) {
            dp[j+1][j+i] = max(dp[j+1][j+i], dp[j][j+i]+abs(v[i].se-j)*v[i].fi);
            dp[j][j+i-1] = max(dp[j][j+i-1], dp[j][j+i]+abs(v[i].se-(j+i))*v[i].fi);
            ans = max({ans,dp[j+1][j+i],dp[j][j+i-1]});
        }

    cout << ans << endl;
    return 0;
}

