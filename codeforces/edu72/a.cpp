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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);


ll bin(ll a, ll b, ll c) {
    ll l = 0;
    ll r = c;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        ll out = c-mid;
        if(a+out > b+mid) ans = mid, l = mid+1;
        else r = mid-1;
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a,b,c;
        cin >> a >> b >> c;
        if(c <= 0) { cout << (a > b? 1 : 0) << endl; continue; }
        cout << bin(a,b,c) << endl;
    }



    return 0;
}

