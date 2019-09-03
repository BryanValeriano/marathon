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
	set<int> v;
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		v.insert(x);
	}
	if(v.size() <= 2) {
		cout << "YES" << endl;
	}
	else if(v.size() == 3) {
		int z[3];
		int i = 0;
		for(auto y : v) z[i] = y, i++;
		if(abs(z[1] - z[0]) == abs(z[1] - z[2])) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else cout << "NO" << endl;
	

    
    
    return 0;
}
