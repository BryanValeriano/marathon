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

const int T = 39;
ll v[T];

ll check(ll z) {
    ll ans = 0;
    for(int i = T-1; i >= 0; i--) 
        if(ans + v[i] <= z) ans += v[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll x = 1;
    for(int i = 0; i < T; i++) v[i] = x, x*= 3ll;
    int tc; cin >> tc;
    while(tc--) {
        ll z; cin >> z;
        ll l = 0;
        ll r = v[T-1];
        ll ans = r;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(check(mid) >= z) ans = mid, r = mid-1;
            else l = mid+1;
        }

        cout << check(ans) << endl;
    }
    
    return 0;
}

