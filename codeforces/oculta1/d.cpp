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
const int T = 1e5+5;
ll l[T];
ll r[T];

int main() {
    ios_base::sync_with_stdio(false);
	ll n,p; cin >> n >> p;

	for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
	n++; l[n-1] = l[0]; r[n-1] = r[0];

	long double div = 1;
	long double qtd = (r[0] - l[0] +1);
	long double ans = 0;
	
	for(int i = 1; i < n; i++) {
		ll m1 = r[i-1]/p - (l[i-1]-1)/p;
		ll x1 = (r[i-1] - l[i-1]+1) - m1;

		ll m2 = r[i]/p - (l[i]-1)/p;
		ll x2 = (r[i] - l[i]+1) - m2;

		long double tmp = qtd*(long double)((m1*x2) + (m2*x1) + (m1*m2))*2000;
		div *= (long double)(r[i] - l[i] + 1);
		qtd *= (long double)(r[i] - l[i] + 1);
		ans += tmp;
		cout << tmp << endl;
	}

	div /= r[0]-l[0]+1;
	ans /= div;

	cout << setprecision(6) << fixed << ans << endl;
    return 0;
}

