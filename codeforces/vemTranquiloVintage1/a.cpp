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
const int T = 1e3+2;
const ll MOD = 1e9+7;
ll c[T];
ll choose[T][T];

void pre() {
	for(int i = 0; i < T; i++) {
		choose[i][0] = 1;
		choose[i][i] = 1;
	}

	for(int i = 1; i < T; i++) 
		for(int j = 1; j < T; j++) 
			choose[i][j] = choose[i-1][j-1] + choose[i-1][j];

}

int main() {
    ios_base::sync_with_stdio(false);
	pre();
	ll k; cin >> k;
	ll n = 0;

	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		n += c[i];
	}

	ll ans = 1;
	ll qtd = 0;
	ll lugaresDisp = n - k;

	for(int i = 1; i <= k; i++) {
		lugaresDisp++;
		cout << lugaresDisp << endl;
		ll tmp = choose[lugaresDisp + c[i] - 2][c[i] - 1];
		ans = (ans * tmp) % MOD;
		lugaresDisp -= c[i];
	}
	
	cout << ans << endl;
    return 0;
}

