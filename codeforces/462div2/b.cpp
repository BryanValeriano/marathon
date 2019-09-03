#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int k; cin >> k;

	if(k > 36) {
		cout << -1 << endl;
		return 0;
	}
	else {
		if(k < 2) {
			cout << 1;
		}
		while(k - 2 >= 0) {
			cout << 8;
			k -= 2;
		}
		while(k--) {
			cout << 0;
		}
		cout << endl;
	}
	//ll tmp = 1e18;
	//printf("%lld\n", tmp);
    return 0;
}

