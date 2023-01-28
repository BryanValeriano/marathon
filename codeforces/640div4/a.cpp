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

int main() {
	int tc; cin >> tc;
	while(tc--) {
		vector<int> ans;
		int x; cin >> x;
		int casa = 1;
		while(x) {
			int tmp = x % 10;
			if(tmp) ans.pb(tmp*casa);
			x /= 10;
			casa *= 10;
		}
		cout << ans.size() << endl;
		for(auto v : ans) cout << v << " ";
		cout << endl;
	}
    ios_base::sync_with_stdio(false);
    return 0;
}

