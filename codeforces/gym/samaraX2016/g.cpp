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

	ll a, b, a1, a2, b1, b2;
	cin >> a >> b >> a1 >> b1 >> a2 >> b2;

	if((a1 + a2 <= a && max(b1, b2) <= b) || (a1 + b2 <= a && max(b1, a2) <= b) || (b1 + a2 <= a && max(a1, b2) <= b) || (b1 + b2 <= a && max(a1, a2) <= b) || (a1 + a2 <= b && max(b1, b2) <= a) || (a1 + b2 <= b && max(b1, a2) <= a) || (b1 + a2 <= b && max(a1, b2) <= a) || (b1 + b2 <= b && max(a1, a2) <= a))
		cout << "YES" <<  endl;
	else
		cout << "NO" << endl;
    
    return 0;
}
