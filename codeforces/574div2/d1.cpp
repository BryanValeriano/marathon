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
 
const int T = 1e5 + 5;
const int MOD = 998244353;
 
int casa[T][2];
ll mult[T];
ll n;
 
void pre() {
	int cont = 1;
	for(int i = 1; i < T; i++)
		for(int j = 0; j < 2; j++)
			casa[i][j] = cont++;
	
	ll d = 10;
	mult[1] = 1;
 
	for(int i = 2; i < T; i++) {
		mult[i] = (mult[i-1] * d) % MOD;
	}
}
 
ll pega(int x) {
	int c = 1;
	ll ans = 0;
 
	while(x) {
		ll d = x % 10;
		x /= 10;
		ll k1 = (mult[casa[c][0]] * d) % MOD;
		ll k2 = (mult[casa[c][1]] * d) % MOD;
		k1 = (k1*n) % MOD;
		k2 = (k2*n) % MOD;
		ans = (ans + k1) % MOD;
		ans = (ans + k2) % MOD;
		c++;
	}
 
	return ans;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
	pre();
 
	cin >> n;
	ll x;
	ll ans = 0;
 
	for(int i = 0; i < n; i++) {
		cin >> x;
		ans = (ans + pega(x)) % MOD;
	}
   
	cout << ans << endl;
 
    return 0;
}
