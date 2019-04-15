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

	ll a,b; cin >> a >> b;

	while((a >= 2LL*b or b >= (2LL*a)) and a > 0 and b > 0) {
		if(a >= 2LL*b and b > 0) {
			ll vezes = a / (2LL*b);
			a -= vezes * 2LL*b;
		}
		if(b >= 2LL*a and a > 0) {
			ll vezes = b / (2LL * a);
			b -= vezes * 2LL * a;
		}
	}


	cout << a << " " << b << endl; 
    
    return 0;
}
