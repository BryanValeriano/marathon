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
		int x,y,z; cin >> x >> y >> z;
		int a,b,c;
		bool ok = 0;
		for(int i = 0; i < 8 && (!ok); i++) {
			a = (i&1? x : y);
			b = (i&2? x : z);
			c = (i&4? y : z);
			ok |= (x == max(a,b) && y == max(a,c) && z == max(b,c));
		}
		if(ok) {
			cout << "YES\n";
			cout << a << " " << b << " " << c << endl;

		} else cout << "NO\n";
	}
    return 0;
}

