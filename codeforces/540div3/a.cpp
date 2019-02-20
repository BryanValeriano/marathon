#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll n,a,b;
        cin >> n >> a >> b;
        ll ans = 0;
        if(a <= (double)b/2) ans = a*n;
        else {
            ans = n/2 * b;
            if(n & 1) ans += a;
        }
        cout << ans << endl;
    }
    return 0;
}

