#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 
 
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(void) {
	ios::sync_with_stdio(false);
 
	int n;
	cin >>n;
	vector<ll> v;
 
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.pb(a);
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	ll ant = 0;
	for(ll at:v) {
		if(at != ant+1 and at > sum+1) {
			cout <<sum+1 <<endl;
			return 0;
		}
		sum += at;
		ant = at;
	}
	cout <<sum+1 <<endl;
 
	return 0;
}
