#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
vector<ii> v;


int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int l,r;

    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        v.eb(l,r);
    }
    
    sort(v.begin(), v.end(), [] (const ii &a, const ii &b) { return max(a.fi,a.se) > max(b.fi,b.se); });

    ll left = 0;
    ll right = 0;
    ll ans = 0;

    for(auto a : v) {
        ll x1 = (a.fi * left) + (a.se * ((n-left-1))); 
        ll x2 = (a.se * right) + (a.fi * ((n-right-1)));

        if(x1 < x2) ans += x1, left++;
        else if(x2 < x1) ans += x2, right++;
        else if(left < right) ans += x1, left++;
        else ans += x2, right++;
    }

    cout << ans << endl;

    return 0;
}

