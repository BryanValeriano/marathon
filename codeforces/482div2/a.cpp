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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	n++;
	if(n == 1) { cout << 0 << endl; return 0; }
	if(n % 2 == 0) cout << n/2 << endl;
	else cout << n << endl;
    return 0;
}
