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
const int T = 40005;

ll ab;
ll pre[T];

void build(ll a, ll b) {
	ab = a*b;
	pre[0] = 0;
	for(int i = 1; i <= ab; i++) {
		pre[i] = pre[i-1];	
		if((i % a) % b != (i % b) % a) pre[i]++;
	}
}

ll query(ll x) {
	ll full = x/ab;
	ll rem = x%ab;
	return pre[ab]*full + pre[rem];
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		ll a,b,q; cin >> a >> b >> q;
		build(a,b);
		if(a > b) switch(a,b);
		while(q--) {
			ll l,r; cin >> l >> r;
			cout << query(r) - query(l-1) << " ";
		}
		if(tc) cout << endl;
	}
    return 0;
}

