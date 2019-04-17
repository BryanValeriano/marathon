#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
	set<int> bag;
	int n; cin >> n;
	int x;

	for(int i = 0; i < n; i++) {
		cin >> x;
		bag.insert(x);
	}

	if(bag.size() == 1) cout << 0 << endl;
	else if(bag.size() == 2) {
		int ans = *bag.rbegin() - *bag.begin();
		if(!(ans&1)) ans /= 2;
		cout << ans << endl;
	}
	else if(bag.size() == 3) {
		int a[3];
		int i = 0;
		for(auto z : bag) a[i++] = z;
		if(a[1] - a[0] == a[2] - a[1]) cout << a[1] - a[0] << endl;
		else cout << -1 << endl;
	} else cout << -1 << endl; 
    
    return 0;
}
