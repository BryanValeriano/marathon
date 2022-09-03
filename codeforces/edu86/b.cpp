#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool corn(string t) {
	for(int i = 1; i < t.length(); i++)
		if(t[i] != t[i-1]) return false;
	cout << t << endl;
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		string t; cin >> t;
		string s; s = t[0];
		if(corn(t)) continue;
		for(int i = 1; i < t.length(); i++) {
			if(t[i] == t[i-1]) s += ('0' + (!(t[i] - '0')));
			s += t[i];
		}
		cout << s << endl;
	}
    return 0;
}

