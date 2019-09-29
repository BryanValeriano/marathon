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
ll n,k;

bool check(ll x) {
    ll d = n;
    while(d) {
        if(x > k) return 0;
        x = 3*(x-2);
        d--;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    ll l = 3;
    ll r = 1e12;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;
    return 0;
}

