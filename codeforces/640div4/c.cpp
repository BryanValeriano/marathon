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

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		ll n,k; cin >> n >> k;
		ll last = k;
		ll qtd = (last/n);
		ll at = last + qtd;
		while(at/n - last/n) {
			qtd = at/n - last/n;
			last = at;
			at += qtd;
		}
		cout << at << endl;
	}
    return 0;
}

