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

vector<int> ans;
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int last = 1e9 + 7;
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(__gcd(x,last) != 1) {
			for(int i = 2; i < 1e9; i++) {
				if(__gcd(x,i) == 1 and __gcd(last,i) == 1) {
					ans.pb(i);
					break;
				}
			}
		}
		ans.pb(x);
		last = x;
	}
	cout << ans.size() - n << endl;
	for(auto z : ans) cout << z << " ";
	cout << endl;
    return 0;
}
