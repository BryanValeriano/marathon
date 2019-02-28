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

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a, b, aa, bb;
        cin >> a >> b >> aa >> bb;
        ll x = abs(a - aa);
        ll y = abs(b - bb);
        ll ans = 1;
        ans += __gcd(x,y);
        cout << ans << endl;
    }
    return 0;
}

