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

const int T = 2e5 + 10;
pair<int,string> v[T];
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	string tmp;

	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		v[i] = mk(0,tmp);
	}
	
	int q,a,b; cin >> q;

	while(q--) {
		cin >> a >> b;
		v[a] = v[b];
		v[a].fi++;
	}

	for(int i = 0; i < v[1].fi; i++)
		cout << "I_love_";
	cout << v[1].se << endl;

	return 0;
}
