#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 10;
int p[T];
int v[T];
vector<int> ve;
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int x, y;
	for(int i = 0; i < n; i++) {
		cin >> x;
		ve.pb(x);
	}

	sort(ve.begin(), ve.end());
	int at = 0;
	int t = 0;

	while(at < ve.size()) {
		t += ve[at];
		if(t >= T) { cout << -1 << endl; return 0; }
		p[t]++;
		at++;
	}
		
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> x >> y; 
		v[x]++;
		v[y+1]--;
	}
	for(int i = 1; i < T; i++) v[i] += v[i-1];

	at = 0;
	int ok = 0;
	for(int i = 0; i < T; i++) {    
		if(p[i]) at++;
		if(v[i] and at) {
			ok += at;
			at = 0;
		}
		if(ok == ve.size()) { cout << i << endl; return 0; }
	}
		
	cout << -1 << endl;
    return 0;
}

