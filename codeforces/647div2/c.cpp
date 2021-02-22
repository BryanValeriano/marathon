#include <bits/stdc++.h>
using namespace std;

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
const ll LIM = 2e18;

ll solve(ll x) {
    ll ans = 0;

    for(ll i = 1; i <= x; i *= 2ll) {
        ans += x/i;
        if(LIM/2 < i) break;
    }

    return ans;
}

void brute(int x) {
    ll ans = 0;
    ll last = 0;
    for(int i = 1; i <= x; i++) {
        ans += __builtin_popcountll(i^(i-1));
        cout << i << " = " << ans << " / " << ans-last;
        last = ans;
        if(solve(i) != ans) cout << " XXXXXXXXXXXXX ";
        if(solve(i) == ans) cout << " V ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll x; cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}

