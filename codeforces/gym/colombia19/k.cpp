#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define loop(x) for(int i = 0; i < x; i++)
#define each(x, xs) for(auto &x : xs)
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n < 3) cout << 0 << endl;
		else cout << (n / 3) * 2 + 1 - (n % 3 == 0) << endl;
	}

	return 0;
}

