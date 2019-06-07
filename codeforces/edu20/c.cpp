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

ll lim = 1e11;
ll n,k;
vector<ll> divi;

bool check(ll x) {
	x = divi[x];
	if((lim/x) <= (k*(k+1))) return true;
	return (x*((k*(k+1))/2) > n);
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> k;
	
	if(k > 2e5) { cout << -1 << endl; return 0; }

	for(ll i = 1; i*i <= n; i++) 
		if(!(n%i)) divi.pb(i), divi.pb(n/i);

	divi.pb(n);
	sort(divi.begin(), divi.end());

	ll l = 0;
	ll r = divi.size()-1;
	
	while(l <= r) {
		ll mid = (l+r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	
	if(l > 0) l--;
	l = divi[l];
	ll sum = 0;
	ll at = l;


	vector<ll> ans;		
	set<ll> bag;

	for(int i = 0; i < k-1; i++) {
		sum += at;
		ans.pb(at);
		bag.insert(at);
		at += l;
	}
	
	ans.pb(n-sum);
	bag.insert(n-sum);
	sum += (n-sum);

	if(bag.size() == ans.size() and *ans.rbegin() > 0) {
		for(auto z : ans) cout << z << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
		return 0;
	}
    
    return 0;
}

