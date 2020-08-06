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
const int T = 1e5 + 10;

bool ok(ll x, const vector<ll> &v) {
    for(auto y : v) x -= x%y;
    return (x==2);
}

int main() {
    ios_base::sync_with_stdio(false);
    int k; cin >> k;
    ll ans1 = 2, ans2 = 2;
    vector<ll>v;

    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    for(int i = k-1; i >= 0; i--) {
        ans1 = ((ans1/v[i])+(ans1%v[i]?1:0))*v[i];
        ans2 = (ans2/v[i]+1)*v[i]-1;
    }

    if(ok(ans1,v)) cout << ans1 << " " << ans2 << endl;
    else cout << -1 << endl;

    return 0;
}

