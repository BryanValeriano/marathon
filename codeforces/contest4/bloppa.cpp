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

const int N = 1e5 + 5;
int n, k, m;
string w[N];
ll a[N], cost[N], group[N];
map <string, int> mp;

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> m;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
		mp[w[i]] = i;
	}

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < k; i++) {
		int x;	cin >> x;
		cost[i] = INF;
		while (x--) {
			int id;	cin >> id;	id--;
			group[id] = i;
			cost[i] = min(cost[i], a[id]);
		}
	}

	ll res = 0;
	for (int i = 0; i < m; i++) {
		string s;	cin >> s;
		res += cost[group[mp[s]]];;
	}

	cout << res << endl;

	return 0;
}
