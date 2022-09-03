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

int main() {
    ios_base::sync_with_stdio(false);
	int n,d;
	vector<ii> friends;
	cin >> n >> d;
	for(int i = 0; i < n; i++) {
		int m, s; cin >> m >> s;
		friends.eb(m,s);
	}
	sort(friends.begin(), friends.end());

	int r = 0;
	ll ans = 0;
	ll tmp = 0;

	for(int l = 0; l < n; l++) {
		r = max(r,l);
		if(l) tmp -= friends[l-1].se;
		tmp = max(tmp, friends[l].se);
		while(r+1 < n && friends[r+1].fi - friends[l].fi < d) {
			r++;
			tmp += friends[r].se;
		}
		ans = max(ans,tmp);
	}

	cout << ans << endl;
    return 0;
}

