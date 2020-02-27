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

ll n,m,k;
vector<ll> lin;
vector<ll> col;

bool check(ll x) {
    ll l = 0;
    ll r = m-1;
    ll ans = 0;

    while(l < n) {
        while(r >= 0 and lin[l] * col[r] > x) r--;
        ans += r+1;
        l++;
    }

    return (ans >= k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) lin.pb(i);
    for(int i = 1; i <= m; i++) col.pb(i);

    ll l = 1;
    ll r = 1e12;

    ll ans = 1;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans << endl;

    return 0;
}

