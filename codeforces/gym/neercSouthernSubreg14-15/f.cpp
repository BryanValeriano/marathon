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
 
const int T = 2e5 + 5;
 
vector<ll> v;
vector<ll> v3;
ll maxi[T];
int n,k;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	int x;
 
	for(int i = 0; i < n; i++) cin >> x, v.pb(x);
	ll ans = 0;
	
	ll tot = 0;
    ll corner = 0;
	ll best = 0;
	ll l = 0;
	for(int i = 0; i < n; i++) {
        corner += v[i];
		tot += v[i];
		if(i >= k) tot -= v[i-k];
		if(i >= k-1) v3.pb(tot);	
		if(tot > best) l = i;
		best = max(best, tot);
	}
	for(int i = v3.size() -1; i >= 0; i--) 
		maxi[i] = max(maxi[i+1], v3[i]);
 
	for(int i = 0; i < v3.size(); i++) 
		ans = max(ans, v3[i] + maxi[i+k]);
	
    if(2*k >= n) ans = corner;
	cout << ans << endl;
	return 0;
}
