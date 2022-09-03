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
	ll a,b; cin >> a >> b;
	ll ans1, ans2;
	ans1 = ans2 = 0;
	bool ok = 1;

	for(int i = 0; i < 400; i++) {
		ll x = (i%a%b);
		ll y = (i%b%a);
		if(x==y) {
			if(!ok) {
				ok = 1;
				cout << endl;
			}
			cout << i << ", ";
			ans1++;
		} else {
			if(ok) {
				ok = 0;
				cout << endl;
			}
			cout << i << ", ";
			ans2++;
		}
	}
	cout << endl << ans1 << " | " << ans2 << endl;
    return 0;
}

