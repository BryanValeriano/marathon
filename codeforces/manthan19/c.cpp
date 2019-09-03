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

const ll MOD = 1049;

const int T = 1010;
int m[T][T];

int main() {
    ios_base::sync_with_stdio(false);
	ll ans = 0;
	ll x;
	cin >> x;
	for(ll i = 0; i < x*x; i+=x) {
		for(ll j = i; j < i+x; j++) {;
			m[i/x][j-i] = ((j+1)*(i+1)*MOD) % (x*x);
		}
	}
	for(int j = 0; j < x; j++) {
		ans = 0;
		for(int i = 0; i < x; i++) {
			ans ^= m[i][j];
			cout << m[i][j] << " ";
		}
		cout << ans << endl;
	}

	cout << endl;

	for(int i = 0; i < x; i++) {
		ans = 0;
		for(int j = 0; j < x; j++) {
			ans ^= m[i][j];
			cout << m[i][j] << " ";
		}
		cout << ans << endl;
	}

    return 0;
}

