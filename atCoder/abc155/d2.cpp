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

vector<ll> pos;
vector<ll> neg;
ll n,k;

ll check(ll x) {
    ll ans = 0;

    ll p = neg.size()-1;
    ll nn = neg.size()-1;
    ll pp = pos.size()-1;

    //neg neg
    for(ll i = 0; i < neg.size(); i++) {
        while(p >= 0 and neg[i]*neg[p] <= x) p--;
        ans += min(nn-p, nn-i);
    }

    p = 0;
    //pos pos
    for(ll i = pos.size()-1; i >= 0; i--) {
        while(p < pos.size() and pos[i]*pos[p] <= x) p++;
        ans += min(p,i);
    }

    p = pos.size()-1;
    //neg pos
    for(int i = neg.size()-1; i >= 0; i--) {
        while(p >= 0 and neg[i]*pos[p] <= x) p--;
        ans += pp-p;
    }

    return (ans >= k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if(x >= 0) pos.pb(x);
        else neg.pb(x);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    ll l = -1e18-5;
    ll ans = 0;
    ll r = 1e18+5;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans << endl;

    return 0;
}

