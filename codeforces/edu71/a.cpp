#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);
	ll tc; cin >> tc;
	while(tc--) {
		ll b,p,f,h,c;
		cin >> b >> p >> f >> h >> c;

		ll ans1 = 0;
		ll ans2 = 0;

		ll carne = 0;
		ll frango = 0;

		carne = min(b/2,p);
		ll b2 = b - carne*2;
		frango = min(b2/2,f);

		ans1 = (carne*h + frango*c);

		frango = min(b/2,f);
		b2 = b - frango*2;
		carne = min(b2/2,p);

		ans2 = (carne*h + frango*c);

		cout << max(ans1,ans2) << endl;
	}


	return 0;
}
