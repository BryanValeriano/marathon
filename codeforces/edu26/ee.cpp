#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;
 
#define INF                0x3f3f3f3f3f3f3f3fll
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
 
auto divs(ll x) {
	vector<ll> d(1, 1);
	for (ll i = 2;i * i <= x;i++) {
		while (x % i == 0) {
			d.push_back(i);
			x /= i;
		}
	}
	if (x > 1) d.push_back(x);
	sort(iter(d));
	return d;
}
 
ll mdc(ll x, ll y) {
	if (x == 0) return y;
	if (y == 0) return x;
	return mdc(y, x % y);
}
 
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
	ll x, y;
	cin >> x >> y;
	auto ds = divs(x);
	ll l = ds.size(), us = 0;
	vb used(l, false);
	ll gcd = mdc(x, y), ans = 0;
	vector<ll> ops(l);
	auto aux = divs(gcd);
	each(p, aux) {
		ll i = find(iter(ds), p) - ds.begin();
		ds[i] = -1;
		used[i] = true;
		us++;
		ops[i] = INF;
	}
	while (y) {
		if (us == l) {
			ans += y / gcd;
			break;
		}
		ll next = 0;
		loop(l) {
			if (!used[i]) {
				ops[i] = (y - (y / (ds[i] * gcd)) * ds[i] * gcd) / gcd;
				if (ops[next] >= ops[i]) next = i;
			}
		}
        cout << ds[next] << " " << ops[next] << endl;
		used[next] = true;
		us++;
		ans += ops[next];
		y -= ops[next] * gcd;
		ops[next] = INF;
		gcd *= ds[next];
	}
	cout << ans <<  endl;
	return 0;
}
