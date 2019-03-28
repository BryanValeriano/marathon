#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	ll tmp = n;
	for(int i = 0; i <= 60; i++) {
		tmp *= (i == 0? 1 : 2);
		if(tmp == m) { cout << i << endl; return 0; }
		if(tmp < m) {
			ll tmp2 = tmp;
			for(int j = 1; j <= 60; j++) {
				tmp2 *= 3;
				if(tmp2 == m) { cout << i+j << endl; return 0; }
			}
		}
		else break;
	}
	cout << -1 << endl;
	return 0;
}
