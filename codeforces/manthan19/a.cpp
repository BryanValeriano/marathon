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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll a,b, n;

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		cin >> a >> b >> n;
		if(n % 3 == 0) cout << a;
		else if(n % 3 == 1) cout << b;
		else cout << (a^b);
		cout << endl;
	}
    return 0;
}

