#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	char x;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		int z = x -'0';
		if(x % 2 == 0) ans += i;
	}
	cout << ans << endl;

	return 0;
}
