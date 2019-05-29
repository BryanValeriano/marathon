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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e7 + 2;
vii track;
vii ans;

bool calc(int x) {
	if(track[x].fi != 0 and !track[x].se) { 
		ans.eb(x/track[x].fi, track[x].fi);
		track[x].se = 1;
		return true;
	} else {
		int ini = track[x].fi;
		for(int i = ini + 1; i*i <= x; i++) {
			if(!(x % i)) {
				track[x] = ii(i, 0);
				if(i*i == x) track[x].se = 1;
				ans.eb(i, x/i);
				return true;
			}
		}
	}

	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int x;
	track.resize(N,{0,0});

	for(int i = 0; i < n; i++) {
		cin >> x;
		if(!calc(x)) { cout << "NO" << endl; return 0; }
	}
	cout << "YES" << endl;
	for(auto z : ans) cout << z.fi << " " << z.se << endl;

	return 0;
}

