#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
 
vector<ll>acima;

int main() {
    ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll x = 0;


	for(ll i = 1; i*i <= n; i++) {
		if(n % i == 0) {
			x++;
			acima.pb(i);
			if(i*i != n) acima.pb(n/i);
		}
		if(x == k) { cout << i << endl; return 0; }
	}

	sort(acima.begin(), acima.end());

	for(int i = 0; i < acima.size(); i++)
		if(i+1 == k) { cout << acima[i] << endl; return 0; }

	cout << -1 << endl;	
    return 0;
}
