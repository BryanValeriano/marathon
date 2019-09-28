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
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        ll ok = -11;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            if(abs(x-ok) > 10) ans++, ok = x+10;
        }

        cout << ans << endl;
    }
    return 0;
}

