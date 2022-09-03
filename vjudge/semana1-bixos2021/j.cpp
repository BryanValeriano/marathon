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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int r; cin >> r;
        int ans = 0;
        for(ll i = 1; i < 10; i++) {
            ll x = i;
            while(x <= r) {
                ans ++;
                x *= 10ll;
                x += i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

