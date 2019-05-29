#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define cc(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;

vector<ii> v;

bool cmp(const ii &a, const ii &b) {
	return (a.se - a.fi > b.se - b.fi);
}

int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int x,y;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		v.eb(y,x);
	}

	sort(v.begin(), v.end(), cmp);

	ll at = 0;
	ll tot = 0;

	for(auto z : v) {
		if(at < z.se) {
			tot += z.se - at;
			at += z.se - at;
		}
		at -= z.fi;
	}

	cout << tot << endl;
    
    return 0;
}

