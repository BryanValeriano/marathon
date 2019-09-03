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
 
int main() {
    ios_base::sync_with_stdio(false);
	ll n,k,can,x;
	cin >> n >> k;
	can = k*2LL;

	for(int i = 0; i < n; i++) {
		cin >> x;
		v.pb(x);
	}

	sort(v.begin(), v.end());
	int ans = 0;

	for(int i = 0; i < n; i++) {
		can = k*2LL;
		if(can >= v[i]) k = max(k,v[i]);
		else {
			while(can < v[i]) {
				k = can;
				can = k*2LL;
				ans++;
			}
			k = max(k,v[i]);
		}
	}

	cout << ans << endl; 
    
    return 0;
}

