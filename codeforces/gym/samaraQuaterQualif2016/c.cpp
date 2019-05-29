#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define cc(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int N = 1e6+5;

int main() {
    ios_base::sync_with_stdio(false);

    ll p;
	cin >>p;
	ll ans[N];
	memset(ans, -1, sizeof(ans));

	for(ll i = 0; i < p; i++) {
		ll x = i*i;
		x %= p;
		ans[x] = i;
	}

	for(ll i = 0; i < p; i++) {
		cout <<ans[i] <<' ';
	}
	cout <<endl;
    
    return 0;
}

