#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 
 
typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
vector<ii> v;
int n;
 
int main(void) {
	ios::sync_with_stdio(false);
 
	cin >> n;
	ll a,b;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.eb(a,b);
	}
 
	sort(v.begin(), v.end(), [&] (const ii &x, const ii &y) {
		if(x.se != y.se) return x.se < y.se; 
		return x.fi < y.fi;
	});
 
	ll maxi =v[0].fi - v[0].se;
	ll sum = 0;
 
	for(int i = 0; i < n; i++) {
		sum += v[i].fi;
		maxi = max(maxi, sum-v[i].se);
	}
 
	cout << maxi << endl;
 
	return 0;
}
