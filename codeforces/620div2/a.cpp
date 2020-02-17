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
ll x,y,a,b;

bool check(ll mid) {
    return x + mid*a >= y - mid*b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> x >> y >> a >> b;

        ll l = 0;
        ll ans = 0;
        ll r = 1e9 + 5;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(check(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }

        cout << (x + ans*a == y - ans*b? ans : -1) << endl;

    }
    return 0;
}

