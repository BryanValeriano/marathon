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

unordered_map<int,int> bag;
 
int main() {
    ios_base::sync_with_stdio(false);
	int k, n, x;
	string ans;
	cin >> k >> n;

	for(int i = 0; i < n; i++) {
		cin >> x;
		bag[x]++;
		if(bag.size() == k) {
			ans += '1';
			vector<int> tira;
			vector<int> diminui;
			for(auto z : bag) {
				if(z.se == 1) tira.pb(z.fi);
				else diminui.pb(z.fi);
			}
			for(auto z : tira) bag.erase(z);
			for(auto z : diminui) bag[z]--;
		}
		else ans += '0';
	}

	cout << ans << endl; 
    
    return 0;
}
