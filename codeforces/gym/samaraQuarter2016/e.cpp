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

struct node {
	int v, op;

	bool operator < (const node &t) const {
		if(v != t.v) return v < t.v;
		return op < t.op;
	}
};

vector<node> v;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;

	for(int i = 0; i < n; i++) {
		int a, b; cin >>a >>b;
		v.pb({a, 0});
		v.pb({b, 1});
	}
    
	sort(v.begin(), v.end());
	
	int ans = 0;
	for(int i = v.size()-1; i >= 0; i--) {
		if(v[i].op == 1) ans++;
		else break;
	}
	cout <<ans <<endl;

    return 0;
}

