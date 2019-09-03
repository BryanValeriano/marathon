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
int x,y;
int a,b;

int dp[310][310];

bool test(int n, int z, int k) {
	if(dp[z][k] != -1) return dp[z][k];
	if(z + k == n) { x = z; y = k; return true; }
	if(z + k > n) return false;
	return dp[z][k] = (test(n, z+a, k) or test(n, z, k+b));
}
 
int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	memset(dp,-1,sizeof dp);
	if(test(n,0,0)) {
		cout << (x/a) + (y/b) << endl;
		for(int i = 0; i < x; i++) {
			cout << s[i];
			if((i+1) % a == 0) cout << endl;
		}
		for(int j = x; j < x+y; j++) {
			cout << s[j];
			if((j-x+1) % b == 0) cout << endl;
		}
	} else cout << -1 << endl;
				
    return 0;
}
