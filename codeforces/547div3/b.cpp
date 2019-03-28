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

const int T = 2e5 + 10;
int v[T+T];
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int tmp = 0;
	int maxi = 0;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = n; i < 2*n; i++) v[i] = v[i-n];
	for(int i = 0; i < 2*n; i++) {
		if(v[i]) tmp++;
		else tmp = 0;
		maxi = max(maxi,tmp);
	}
	cout << maxi << endl;

	return 0;
}
