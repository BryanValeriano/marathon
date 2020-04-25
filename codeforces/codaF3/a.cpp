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
ll n,a,b,c;

bool check(ll x) {
    return n-(x*(b-c)) >= b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> a >> b >> c;
    if(a <= b-c) cout << n/a << endl;
    else {
        ll l = 0;
        ll r = n/(b-c)+1ll;
        ll ans = 0;
        while(l<=r) {
            ll mid = (l+r)>>1;
            if(check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        n -= ans*(b-c);
        if(n >= b) ans++, n -= (b-c);
        ans += n/a;
        cout << ans << endl;

    }
    return 0;
}

