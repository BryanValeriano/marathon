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
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int mini = INF;
		int pos = 0;
		vector<int> v;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			if(x < mini) { mini = x; pos = i; }
			v.pb(x);
		}
		for(int i = 0; i < n; i++) {
			if(i == pos) {
				cout << 2 << " ";
				continue;
			}
			cout << (v[i]&1? v[i]+1 : v[i]) << " ";
		}
		cout << endl;
	}
    return 0;
}

