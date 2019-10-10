#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	ll n, m;
	cin >>n >>m;
	while(m--) {
		ll x, k;
		cin >>x >>k;
		k %= n;
		while(k--) {
			ll t = (x&(1LL<<(n-1))) > 0;
			x -= (x&(1LL<<(n-1)));
			x <<= 1LL;
			x |= t;
		}
		cout <<x <<endl;
	}
	
	return 0;
}
 
