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
const int MOD = 1e9 + 7;
 
ll exp(ll base, ll e) {
	ll ans = 1;
	while(e) {
		if(e&1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		e >>= 1;
	}

	return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
	ll x,k; cin >> x >> k;
    if(x == 0) { cout << x << endl; return 0; }

	x %= MOD;
	//k %= MOD;
	
	ll maior = (exp(2,k+1) * x) % MOD;
	ll menor = (((maior - (exp(2,k+1)-2)) % MOD) + MOD ) % MOD;

	

	ll ans = (maior + menor) % MOD;
	ans = (ans * exp(2, MOD-2)) % MOD;

	cout << ans << endl;
    
    return 0;
}
