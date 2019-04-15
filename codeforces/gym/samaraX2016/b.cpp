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
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 10;
vector<int> troca;
vector<ii> ans;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin  >> n;
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		if(v[i] == i) {
			troca.pb(i);
		}
	}
	for(int i = 0; i+1 < troca.size(); i += 2) 
		ans.pb({troca[i], troca[i+1]});
	
	if((int)(troca.size() & 1)) 
		for(int i = 1; i <= n; i++) 
			if(v[i] != *troca.rbegin()) { 
				ans.pb({i, *troca.rbegin()});
				break;
			}

	cout << ans.size() << endl;
	for(auto x : ans) cout << x.fi << " " << x.se << endl;
    
    
    return 0;
}
