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
 
int main() {
    ios_base::sync_with_stdio(false);
	string x = "abcdefghijklmnopqrstuvwxyz";
	int ini = 0;
	string s; cin >> s;
	

	for(int i = 0; i < s.size(); i++) {
		if(ini == x.size()) {
			cout << s << endl;
			return 0;
		}
		if(s[i] <= x[ini]) { 
			s[i] = x[ini];
			ini++;
		}
	}


	if(ini == x.size()) {
		cout << s << endl;
		return 0;
	}
    
	cout << -1 << endl; 
    return 0;
}
