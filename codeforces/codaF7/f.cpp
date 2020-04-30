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

ll base(ll x, ll b) {
    ll ans = 0;
    while(x >= b) {
        ll tmp = b;
        while(tmp*b <= x) tmp *= b;
        ll l = 0;
        ll r = b-1;
        ll dig = 0;
        while(l<=r) {
            ll mid = (l+r)>>1;
            if(tmp*mid <= x) dig = mid, l = mid+1;
            else r = mid-1;
        }
        ans += dig;
        x -= dig*tmp;
    }
    return ans+x;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll a; cin >> a;
    ll sum = 0;
    for(int i = 2; i < a; i++) sum += base(a,i);
    ll gcd = __gcd(sum,a-2);
    cout << sum/gcd << "/" << (a-2)/gcd << endl;

    return 0;
}

