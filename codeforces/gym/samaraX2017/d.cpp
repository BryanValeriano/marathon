#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);
	
	int n, x;
	cin >>n >>x;
	
	int ans;
	cin >>ans;
	for(int i = 1; i < n; i++) {
		int v; cin >>v;
		ans = __gcd(ans, v);
	}

	if(x%ans == 0) cout <<"YES" <<endl;
	else cout <<"NO" <<endl;

	return 0;
}
