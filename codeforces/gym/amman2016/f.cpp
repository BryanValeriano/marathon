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
 
int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		string s; cin >> s;

		set<char> bag;
		vector<char> track;

		for(int i = 0; i < s.size(); i++) 
			bag.insert(s[i]);

		for(auto x : bag) track.pb(x);	

		int j = 0;
		char a = 'a';
		char b = 'a';
		bool vis[30];
		memset(vis, 0, sizeof vis);

		for(int i = 0; i < s.size(); i++) {
			while(j < track.size() and vis[track[j] - 'a']) j++;
			if(j < track.size() and s[i] != track[j] and s[i] > track[j] and !vis[track[j] - 'a']) {
				a = s[i];
				b = track[j];
				break;
			}
			vis[s[i] - 'a'] = true;
		}

		for(int i = 0; i < s.size(); i++) {	
			if(s[i] == a) cout << b;
			else if(s[i] == b) cout << a;
			else cout << s[i];
		}

		cout << endl;
    
	} 
    return 0;
}

