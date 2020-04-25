#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

#define left(id) id << 1
#define right(id) id << 1 | 1

const ll mod = 1000000007;

const int N = 4*(50010);
vi st(N, 0), lazy(N, 0), cnt(10000, 0);

void prop(int id, int l, int r) {
	if (lazy[id]) {
		if (l != r) {
			lazy[left(id)] += lazy[id];
			lazy[right(id)] += lazy[id];
		}
		if (l == r) {
			cnt[l] += lazy[id];
			st[id] = cnt[l] > 0;
		}
		else {
			if (lazy[id] > 0) {
				st[id] = r - l + 1;
			}
			else {
				int mid = avg(l, r);
				prop(left(id), l, mid);
				prop(right(id), mid + 1, r);
				st[id] = st[left(id)] + st[right(id)];
			}
		}
		lazy[id] = 0;
	}
}

void update(int id, int l, int r, int a, int b, int val) {
	prop(id, l, r);
	if (r < a or l > b) return;
	if (a <= l and r <= b) {
		lazy[id] += val;
		prop(id, l, r);
	}
	else {
		int mid = avg(l, r);
		update(left(id), l, mid, a, b, val);
		update(right(id), mid + 1, r, a, b, val);
		st[id] = st[left(id)] + st[right(id)];
	}
}

typedef tuple<int, int, int, int> tup;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<tup> sl;
	int a, b, c, d, m = 0;
	loop(n) {
		cin >> a >> b >> c >> d;
		m = max({m, b, d});
		sl.emplace_back(a, b, d, 1);
		sl.emplace_back(c, b, d, -1);
	}
	sort(iter(sl));
	int x, l, r, val, last = 0;
	int ans = 0;
	each(t, sl) {
		tie(x, l, r, val) = t;
		prop(1, 0, m - 1);
		ans += (x - last) * st[1];
		update(1, 0, m - 1, l, r - 1, val);
		last = x;
	}
	cout << ans << endl;
	return 0;
}

