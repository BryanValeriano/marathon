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
const int T = 4e6;

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	vii v;

	int k = 1;
	for(int i = 1; i < T; i += k) {
		v.eb(i,k);
		k++;
	}

	while(tc--) {
		int x; cin >> x;
		auto ok = lower_bound(v.begin(), v.end(), mk(x,0));
		int ans = ok->se;
		if(ok->fi-1 == x) ans++;
		cout << max(1,ans) << endl;
	}
    return 0;
}

