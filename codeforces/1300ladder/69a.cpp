#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int n; cin >> n;
	int a, b, c;
	int x, y, z;
	a = b = c = 0;
	
	while(n--) {
		cin >> x >> y >> z;
		a += x;
		b += y;
		c += z;
	}
	if(a == b && b == c && c == 0) cout << "YES";
	else cout << "NO";
	cout << endl;
    return 0;
}

