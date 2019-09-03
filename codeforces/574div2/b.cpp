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
 
ll n,k;
 
bool check(ll x) {
	ll tot = (x*(x+1)/2);
	ll sobra = n-x;
	return (tot-sobra < k);
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> k;
 
	ll ans = 0;
	
	ll l = 0;
	ll r = n;
 
	while(l <= r) {
		ll mid = (l+r) >> 1;
		if(check(mid)) l = mid+1;
		else r = mid-1;
	}
   
 
	cout << n-l << endl;
 
    return 0;
}
