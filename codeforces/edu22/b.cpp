#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> v;
set<ll> tmp;
const ll lim = 1e18;

ll ele(ll base, ll e) {
	ll ans = 1;
	for(ll i = 1; i <= e; i++) {
		if(lim/ans < base) return 0;
		ans *= base;
	}
	return ans;
}

bool flag1 = 1;
bool flag2 = 1;
ll l,r,le,re;

ll corner1() {
	return (flag1 and le == l);
}

ll corner2() {
	return (flag2 and re == r);
}

int main() {
    ios_base::sync_with_stdio(false);
	ll a,b;
	cin >> a >> b >> l >> r;

	
	for(ll i = 0; i < 62; i++) {
		for(ll j = 0; j < 62; j++) {
			ll x = ele(a,i);
			ll y = ele(b,j);
			if(!x or !y or lim-x < y) continue;
			v.pb(x+y);
			if(x+y == l) flag1 = 0;
			if(x+y == r) flag2 = 0;
		}
	}
	
	v.pb(l);
	v.pb(r);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	ll best = 0;

	for(int i = 1; i < v.size(); i++) {
		re = min(r, v[i]);
		le = max(l, v[i-1]);
		best = max(best, re-le-1 + corner1() + corner2());
	}

	cout << best << endl;
	 
    return 0;
}
