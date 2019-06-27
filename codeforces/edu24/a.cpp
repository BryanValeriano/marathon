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
 
ll top = 1e13;
ll lim;
ll n,k;

bool check(ll x) {
	if(x >= lim) return true;
	ll c = x*k;
	return (c+x > n/2);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> k;

	lim = top/k;
	
	ll l = 0;
	ll r = n;

	while(l <= r) {
		ll mid = (l+r) >> 1;
		if(check(mid)) r = mid-1;
		else l = mid+1;
	}

	cout << l-1 << " " << (l-1)*k << " " << (n-((l-1)+(l-1)*k)) << endl;
	    
    
    return 0;
}
