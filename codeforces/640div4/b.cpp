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

vector<int> solve(int n, int k, int x) {
	vector<int> ans;
	while(k > 1) {
		ans.pb(x);
		k--;
		n -= x;
	}
	ans.pb(n);
	if((ans.back()&1) == (ans[0]&1) && (n > 0)) ans.pb(1);
	else ans.pb(0);
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n,k; cin >> n >> k;
		vector<int> ans = solve(n,k,1);
		vector<int> ans2 = solve(n,k,2);
		if(ans.back() == 1) {
			cout << "YES" << endl;
			for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << " ";
			cout << endl;
			continue;
		}
		if(ans2.back() == 1) {
			cout << "YES" << endl;
			for(int i = 0; i < ans2.size()-1; i++) cout << ans2[i] << " ";
			cout << endl;
			continue;
		}
		cout << "NO" << endl;
	}
    return 0;
}

