#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
        ll a,b; cin >> a >> b;
        ll x = b/a;
        ll y = b%a;
        ll ans = x*x*(a - y) + (x+1)*(x+1)*(y);
        cout << ans << endl;
    }
    return 0;
}

