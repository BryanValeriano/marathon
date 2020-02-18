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
        ll gol; cin >> gol;
        ll ans = INF;

        while(n--) {
            ll x; cin >> x;
            if(x == gol) ans = 1;
            else {
                if(x >= gol/2) ans = min(ans,2ll);
                else ans = min(ans,gol/x + (gol%x? 1 : 0));
            }
        }

        cout << ans << endl; 
    } 
    
    return 0;
}

