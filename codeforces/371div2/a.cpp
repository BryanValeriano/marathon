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
	ll l1,r1,l2,r2,k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;

	l1 = max(l1,l2);
	r1 = min(r1,r2);
	ll ans = r1 - l1 + 1;
	if(k >= l1 and k <= r1) ans--;
	cout << max(0LL,ans) << endl;
    
    return 0;
}

