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
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e5 + 5;

set<int> s;
unordered_map<int,int> track;
int ans[N];
 
int main() {
	ios_base::sync_with_stdio(false);
	int n,m,d,x;
	cin >> n >> m >> d;
	
	for(int i = 0; i < n; i++) {	
		cin >> x;
		track[x] = i;
		s.insert(x);
	}

	int t = 1;

	while(s.size()) {
		vector<int> v;
		x = *s.begin();
		v.pb(x);
		auto z = s.lower_bound(x+d+1);

		while(z != s.end()) {
			v.pb(*z);
			x = *z;
			z = s.lower_bound(x+d+1);
		}

		for(int i = 0; i < v.size(); i++) {
			ans[track[v[i]]] = t;
			s.erase(v[i]);
		}
	
		t++;
	}

	cout << t-1 << endl;
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}

