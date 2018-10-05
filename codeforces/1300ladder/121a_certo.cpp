#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const ll inf = 10000000000LL;

vector < ll > a;

void gen(ll current) {
	if (current > inf) {
		return;
	}
	if (current > 0) {
		a.push_back(current);
	}
	gen(current * 10LL + 4LL);
	gen(current * 10LL + 7LL);
}

int main() {
    ios::sync_with_stdio(false);
	gen(0);
	sort(a.begin(), a.end());
    cout << a.size() << endl;

	ll l, r;
	cin >> l >> r;
	ll res = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] < l) {
			continue;
		}
		ll bound = a[i];
		if (bound > r) {
			bound = r;
		}
		if (l <= bound) {
			res += (bound - l + 1) * a[i];
		}
		l = bound + 1;
	}
	cout << res << endl;

	return 0;
}
