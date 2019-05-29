#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 5;

vector<int> topo;
vector<int> ans[T];

int lower(int x) {
	int l = 0;
	int r = (int)topo.size();

	while(l < r) {
		int mid = (l+r) >> 1;
		if(topo[mid] > x) l = mid+1;
		else r = mid;
	}
	return r;
}

int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int x;

	for(int i = 0; i < n; i++) {
		cin >> x;
		if((int)topo.size() == 0) {
			topo.pb(x);
			ans[0].pb(x);
		} else {
			int y = lower(x);
			if(y == (int)topo.size()) {
				topo.pb(x);
				ans[(int)topo.size()-1].pb(x);
			} else {
				topo[y] = x;
				ans[y].pb(x);
			}
		}
	}

	for(int i = 0; i < (int)topo.size(); i++) { 
		for(int j = 0; j < (int)ans[i].size(); j++) {
			cout << ans[i][j] << ((j+1) == (int)ans[i].size()? '\n':' '); }
	}
    
    return 0;
}
