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
		ll x,y,a,b;
		cin >> x >> y >> a >> b;
		if(x > y) swap(x,y);
		ll ans1 = (y-x)*a + x*b;
		ll ans2 = (x+y)*a;
		cout << min(ans1, ans2) << endl;
	}
    return 0;
}

