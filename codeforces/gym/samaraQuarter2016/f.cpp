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
	int a,b,c, id;

	bool operator < (const node &z) const {
		if(a < z.a and b < z.b) return true;
		if(a < z.a and c < z.c) return true;
		if(b < z.b and c < z.c) return true;
		return false;
	}
};


vector<node> v;
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int a,b,c;

	for(int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.pb({a,b,c,i+1});
	}

	sort(v.begin(), v.end());

	int ans = 0;
	node x = v[0];

	for(int i = 1; i < n; i++) 
		if(v[i] < x) { cout << 0 << endl; return 0; }

	cout << 1 << endl << x.id << endl;
    
    return 0;
}

