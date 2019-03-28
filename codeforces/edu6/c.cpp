#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 3e5 + 10;
vii ans;
int v[T];
map<int,int> track;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> v[i];

	int last = 1;
	for(int i = 1; i <= n; i++) {
		track[v[i]]++;
		if(track[v[i]] == 2) {
			ans.eb(last, i);
			last = i+1;
			track.clear();
		}
	}
	if(ans.size() == 0) { cout << -1 << endl; return 0; }
	cout << ans.size() << endl;
	if(ans.rbegin()->se != n) ans.rbegin()->se = n; 
	for(auto x : ans) cout << x.fi << " " << x.se << endl;
    
    return 0;
}
