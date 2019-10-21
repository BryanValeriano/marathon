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

const int T = 1e4 + 2;
ll v[T];
int n;

ll solve(int mini) {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll x = v[i]-mini;
        ans += (x/5);
        x -= 5 * (x/5);
        if(x >= 3) ans += 2;
        else if(x > 0) ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        ll mini = 2e18;
        for(int i = 0; i < n; i++) cin >> v[i], mini = min(mini,v[i]);
        ll ans = 2e18;
        while(mini > -10) ans = min(ans,solve(mini)), mini--;
        cout << ans << endl;
    }
    return 0;
}

