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
	int tc; cin >> tc;
	while(tc--) {
		string a,b;
		int n; cin >> n;
		cin >> a >> b;
		int ansA = 0, ansB = 0;

		while(a.size() or b.size()) {
			char x = '0', y = '0';
			if(a.size()) { x = a.back(); a.pop_back(); }
			if(b.size()) { y = b.back(); b.pop_back(); }
			if(x > y) ansA++;
			else if(y > x) ansB++;
		}
		
		if(ansA == ansB) cout << "EQUAL\n";
		else if(ansA > ansB) cout << "RED\n";
		else cout << "BLUE\n";

	}
    return 0;
}

