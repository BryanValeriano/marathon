#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

vector<int> ans;
unordered_set<int> v;

void pre() {
	for(int i = 0; i <= 30; i++) v.insert(pow(2,i)-1);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	pre();
	int n; cin >> n;
	int k = 0;
	int oper = 0;
	
	while(n and !v.count(n)) {
		if(k != 0) n++, oper++;
		oper++;
		k++;
		int x;
		for(x = 30; x >= 0; x--) if(n & (1<<x)) break;
		ans.pb(x+1);
		x = pow(2,x+1)-1;
		n ^= x;
	}

	if(ans.size() == 0) { cout << 0 << endl; return 0; }

	cout << oper << endl;
	for(auto z : ans) cout << z << " ";
	cout << endl;

	return 0;
}
