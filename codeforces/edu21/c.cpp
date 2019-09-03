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
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 110;
ll qtd[T];
ll ans[T];
ii track[T];

int n;
ll tot;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> tot;
	ll tmp = 0;
	int x;

	for(int i = 0; i < n; i++) {
		cin >> x;
		qtd[i] = x;

		ans[i] = x/2;
		if(x&1) ans[i]++;
		tmp += ans[i];

		track[i] = ii(x,i);
	}

	if(tmp > tot) { cout << -1 << endl; return 0; }
	tot -= tmp;
		
	sort(track, track+n, greater<ii>());	

	for(int i = 0; i < n; i++) {			 
		int at = track[i].se;
		ll x = qtd[at] - ans[at];
		x = min(x, tot);
		ans[at] += x;
		tot -= x;
	}

	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
    
    return 0;
}
