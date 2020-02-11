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
        int k; cin >> k;
        int ans = 0;
        while(k) {
            if(k >= 10) {
                int z = k/10;
                ans += 10 * z;
                k -= 10 * z;
                k += z;
            }
            else ans += k, k = 0;
        }
        cout << ans << endl;
    }
    return 0;
}

