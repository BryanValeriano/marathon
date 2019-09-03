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

const int T = 30;
int a[T];
int b[T];
set<char> pega;
 
int main() {
    ios_base::sync_with_stdio(false);
	string s,t;
	cin >> s >> t;

	for(int i = 0; i < s.size(); i++) a[s[i] - 'a']++;
	for(int i = 0; i < t.size(); i++) b[t[i] - 'a']++, pega.insert(t[i]);

	ll ans = 0;
	for(auto x : pega) {	
		ans += min(a[x - 'a'], b[x - 'a']);
		if(min(a[x - 'a'], b[x - 'a']) == 0) {
			cout << -1 << endl;
			return 0;
		}
	}
 
	cout << ans << endl; 
    return 0;
}
