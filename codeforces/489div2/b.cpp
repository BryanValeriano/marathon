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
	ll a,b,x,y; cin >> a >> b >> x >> y;

	ll xx = x;	
	ll yy = y;
	ll tmp = 2;
	int ans = 0;
	
	while(xx <= yy) {	
		if(xx >= a and xx <= b and yy >= a and yy <= b) 
			if(__gcd(xx,yy) == x and xx*yy/__gcd(xx,yy) == y) {
				ans++;
				if(xx != yy) ans++;
			}
		xx = x * tmp; 
		yy = y / tmp;
		tmp++;
	}
	
	cout << ans << endl;

    return 0;
}

