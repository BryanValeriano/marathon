#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5+5;

ll secondsSave[T];
ll price1[T];
ll created[T];
ll price2[T];
vii v;

int main() {
    ios_base::sync_with_stdio(false);
	ll n,m,k; cin >> n >> m >> k;
	ll x,s; cin >> x >> s;
	ll ans = (x*n);

	m++;
	secondsSave[0] = x;
	price1[0] = 0;

	for(int i = 1; i < m; i++) cin >> secondsSave[i];
	for(int i = 1; i < m; i++) cin >> price1[i];

	for(int i = 0; i < k; i++) cin >> created[i];
	for(int i = 0; i < k; i++) cin >> price2[i];
	for(int i = 0; i < k; i++) v.eb(price2[i], created[i]);
	sort(v.begin(), v.end());
	
	for(int i = 0; i < m; i++) {
		ll timeSaved = 0;
		ll budget = s;
		if(price1[i] <= budget) {
			timeSaved += (x-secondsSave[i])*n;
			budget -= price1[i];
			int best = upper_bound(v.begin(), v.end(), mk(budget, created[k-1])) - v.begin();
			best--;
			if(best >= 0) {
				budget -= v[best].fi;
				if(budget >= 0) timeSaved += v[best].se*secondsSave[i];
			}
		}
		ans = min(ans, x*n - timeSaved);
	}

	ans = max(ans,0ll);
	cout << ans << endl;
    return 0;
}

