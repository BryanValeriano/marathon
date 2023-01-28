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

int main() {
    ios_base::sync_with_stdio(false);
	int n,p; cin >> n >> p;
	string s; cin >> s;
	string t = s;

	bool ans = false;
	for(int i = 0; i < n; i++) {
		if(s[i] == '.') {
			if(i-p >= 0) t[i] = '0' + ('1' - t[i-p]);
			else if(i+p < n) {
				if(s[i+p] != '.') t[i] = '0' + ('1' - s[i+p]);
				else t[i] = '0';
			}
			else t[i] = '0';
		} else t[i] = s[i];
		if(i-p >= 0) ans |= t[i] != s[i-p];
	}
	cout << (ans? t : "No") << endl;
    return 0;
}

