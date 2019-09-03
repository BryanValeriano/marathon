#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 5;
ll ans[T];

struct node {
	ll power;
	ll val;
	ll id;

	node(ll power, ll val, ll id) :
		power(power), val(val), id(id) {}

	bool operator < (const node &b) const {
		if(power != b.power) return power < b.power;
		else return id < b.id;
	}
};

vector<node> v;
multiset<ll> bag;
int n,k;

ll calc() {
	ll sum = 0;
	while(bag.size() > k) bag.erase(bag.begin());
	if(bag.size()) for(ll x : bag) sum += x;
	return sum;
}

ll tmp1[T];
ll tmp2[T];

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 0; i < n; i++) cin >> tmp1[i];
	for(int i = 0; i < n; i++) cin >> tmp2[i];

	for(int i = 0; i < n; i++) v.eb(tmp1[i],tmp2[i],i+1);

	v.pb({-1,-1,-1});

	sort(v.begin(), v.end());
	ll last = 0;

	for(int i = 1; i <= n; i++) {
		if(v[i].power != v[i-1].power) last = calc();
		ans[v[i].id] = last + v[i].val;
		bag.insert(v[i].val);
	}

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;

    return 0;
}

