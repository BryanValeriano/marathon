
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

const int T = 2e5 + 10;
ll v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	ll n,k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) v[i] += v[i-1];

	ll ans = 0;
	ll div = 0;
	for(int i = k; i <= n; i++) {
		ans += v[i] - v[i-k];
		div++;
	}

	cout << fixed << setprecision(6);
	cout << (double)ans/(double)div << endl;
   
    return 0;
}
