#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define int long long 

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f; const double PI = acos(-1.0);

map<int,int> track;
vector<int> two;
set<ii> vis;
vector<int> v;

void pre() {
	for(int i = 0; i < 31; i++) 
		two.pb(pow(2,i));
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
	pre();
	int n, x; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		v.pb(x);
		track[x]++;
	}
   
	ll ans = 0;

	for(int i = 0; i < n; i++) { 
		for(int j = 0; j < two.size(); j++) {
			if(track.count(two[j] - v[i]) and !vis.count(ii(min(two[j] - v[i], v[i]), max(two[j] - v[i], v[i])))) {
				if(two[j] - v[i] != v[i]) ans += track[two[j] - v[i]] * track[v[i]];
				else ans += (track[v[i]]*(track[v[i]] - 1))/2;
				vis.insert(ii(min(two[j] - v[i], v[i]), max(two[j] - v[i], v[i])));
			}
		}
	}

	cout << ans << endl;
    return 0;
}
