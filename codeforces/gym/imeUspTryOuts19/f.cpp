#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e6 + 5;
bitset<T> crivo;
vector<ll> primes;
ll ans = 1;
ll a,b;

void pre() {
	for(int i = 2; i < T; i++) {
		if(!crivo[i]) {
			primes.pb(i);
			for(int j = i+i; j < T; j += i) crivo[j] = 1;
		}
	}
}

void pegaPrimes() {
	int i = 0;
	while(i < primes.size())  {
		if(b % primes[i] == 0) {
			ans *= primes[i];
			while(b % primes[i] == 0) b /= primes[i];
		}
		i++;
	}

	if(b > 1) {
		ll l = 1;
		ll r = sqrt(b) + 1;

		while(l != r) {
			ll mid = (l+r+1) >> 1;
			if(mid*mid > b) r = mid-1;
            else l = mid;
		}

		if(l*l == b) ans *= l;
		else ans *= b;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	pre();
	cin >> a >> b;

	ll gcd = __gcd(a,b);
	b /= gcd;

	pegaPrimes();
	cout << max(2ll,ans) << endl;

    return 0;
}

