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
	
	for(ll i = 0; i <= 9; i++)
		for(ll j = 1; j <= 9; j++) 
			v.pb(j*pow(10LL,i));
	
	ll x; cin >> x;
	auto l = upper_bound(v.begin(), v.end(), x);
	cout << *l -x << endl;
    
    return 0;
}
