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
const int T = 2e5+4;
int v[T], ok[T];

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> v[i];
			ok[i] = 0;
		}
		int ans = 0;
		int mini = INF;
		int maxi = 0;
		for(int i = n; i >= 1; i--) {
			maxi = max(maxi,v[i]);
			if(maxi > v[i]) mini = min(mini,v[i]);
			if(v[i] > mini) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;

	}
    return 0;
}

