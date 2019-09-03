#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct query {
	int t, l, r;

	query () {}

	query (int t, int l, int r) :
		t(t), l(l), r(r) {}
};

const int N = 2e5 + 5;
int n, q, m, a[N];
query v[N];

int go (int x) {

	for (int i = q - 1; i >= 0; i--) {
		int t = v[i].t, l = v[i].l, r = v[i].r;

		if (r < x or l > x)	continue;

		if (t == 1) {
/*			if (x != r)	x++;
			else 		x = l;
*/		
			if (x != l)	x--;
			else		x = r;
		} else {
			int m = r - l;
			x -= l;
			x = m - x;
			x += l;
		}
	}

	cout << x << endl;
	return a[x];
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> q >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < q; i++) {
		cin >> v[i].t >> v[i].l >> v[i].r;
		v[i].l--;
		v[i].r--;
	}

	for (int i = 0; i < m; i++) {
		int x;	cin >> x;
		cout << go (x - 1) << " ";
//		cout << endl;
	}	cout << endl;

	return 0;
}
