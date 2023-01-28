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
const int T = 1e4;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		for(int i = 0; i < n; i++) cin >> v[i];
		int l = 0, r = n-1;
		int moves = 0, alice = 0, bob = 0;
		int lastAlice = 0, lastBob = 0;
		int turn = 0;
		while(l <= r) {
			if(!(turn&1)) {
				lastAlice = 0;
				while(l <= r && lastAlice <= lastBob) lastAlice +=  v[l++];
				alice += lastAlice;
				turn++;
			} else {
				lastBob = 0;
				while(r >= l && lastBob <= lastAlice) lastBob += v[r--];
				bob += lastBob;
				turn++;
			}
		}
		cout << turn << " " << alice << " " << bob << endl;
	}
    return 0;
}

