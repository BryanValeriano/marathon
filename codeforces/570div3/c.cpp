#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int k,n,a,b;

bool check(int x) {
    return (k - (x*a + (n-x)*b) > 0);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> k >> n >> a >> b;

        int l = 0;
        int r = n;
        int ans = -1;
    
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }

        cout << ans << endl;
    
    } 

    return 0;
}

