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
const ll INF = 1e18;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;
vii v;
vector<ll> xs;

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b; cin >> a >> b;

    ll last;
    ll ans = 0;
    ll minX, minY;
    ll maxX, maxY;

    for(int i = 0; i < a; i++) { ll x; cin >> x; xs.pb(x); }

    for(int i = 0; i < b; i++) {
        ll y; cin >> y;
        if(i) {
            ll possibles = (i*(b-i))%MOD;
            ll area = (y-last)%MOD;
            ans = (ans+((area*possibles)%MOD))%MOD;
        } else minY = y;
        last = y;
        maxY = y;
    }

    ll ans1 = ans;
    ans = 0;

    for(int i = 0; i < a; i++) {
        ll x = xs[i];
        if(i) {
            ll possibles = (i*(a-i))%MOD;
            ll area = (x-last)%MOD;
            ans = (ans+((area*possibles)%MOD))%MOD;
        }
        last = x;
    }

    cout << (ans*ans1)%MOD << endl;
    return 0;
}

