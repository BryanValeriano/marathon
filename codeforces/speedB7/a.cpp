#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll a,b;

bool check(ll x) {
    ll l = 0;
    ll r = 1e6 + 3;
    ll mid;

    while(l <= r) {
        mid = (l+r) >> 1;
        if((mid*mid*mid) > x) r = mid-1;
        else if((mid*mid*mid) < x) l = mid+1;
        else break;
    }

    return (mid*mid*mid == x && a%mid == 0 and b%mid == 0);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;

    while(tc--) {
        cin >> a >> b;
        cout << (check(a*b)? "YES" : "NO") << endl;
    }

    return 0;
}

