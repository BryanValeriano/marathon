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
const int T = 8005;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int ans = 0;
		for(int i = 0; i < n; i++) cin >> v[i];
		for(int i = 0; i < n; i++) {
			int l = 0, r = 0, sum = 0;
			while(l < n) {
				while(r < n && sum + v[r] <= v[i]) sum += v[r++];
				if(sum == v[i] && r-l > 1) {
					ans++;
					break;
				}
				if(sum) sum -= v[l];
				l++;
				r = max(r,l);
			}
		}
		cout << ans << endl;
	}
    return 0;
}

