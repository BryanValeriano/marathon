#include <bits/stdc++.h>
using namespace std;

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

ll sumOf(ll x) {
    ll ans = 0;
    while(x) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

bool ok(ll x) {
    return __gcd(x, sumOf(x)) > 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        while(!ok(n)) n++;
        cout << n << endl;
    }
    return 0;
}

