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

string s;
const int T = 1e5 + 10;
bitset<T> vis;

void explode(int ini, int fim) {
	while(ini >= 0 and fim < s.size() and s[ini] == s[fim] and !vis[ini] and !vis[fim]) {
		vis[ini] = true;
		vis[fim] = true;
		ini--;fim++;
	}
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> s;
	ll last = 1; 
	ll fst = s.size();
	while(last != s.size()) {
		vis.reset();
		for(int i = 1; i < s.size(); i++) 
			if(!vis[i] and s[i] == s[i-1]) explode(i-1,i);
		last = s.size();
		string t;
		for(int i = 0; i < s.size(); i++) if(!vis[i]) t += s[i];
		s = t;
	}
	ll ans = fst - s.size();
	ans /= 2;
	cout << (ans&1? "Yes" : "No") << endl;
    return 0;
}
