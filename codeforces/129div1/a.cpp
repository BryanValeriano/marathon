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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
ll l,r;

ll next(ll x) {
	ll ammount = pow(10ll,(ll)log10(x));
	if(x%10 == 9) return ammount*10ll + 1ll;
	return x + ammount + (1ll - (ammount == 1));		
}

ll solve(ll x) {
	if(x > r) return 0;
	ll nxt = next(x);
	return solve(nxt);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> l >> r;
	cout << solve(1) + (ll)(l==1) << endl;
    return 0;
}

