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

int n,m;
vii bag;
vii r;
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        bag.clear();

        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            bag.eb(x,i);
        }

        if(m < n or n == 2) { cout << -1 << endl; continue; }

        sort(bag.begin(),bag.end());
        r.clear();
        ll ans = 0;

        while(m > n) {
            ans += bag[0].fi + bag[1].fi;        
            r.eb(bag[0].se,bag[1].se);
            m--;
        }

        for(int i = 1; i < n; i++) { 
            ans += bag[i].fi + bag[i-1].fi;
            r.eb(bag[i].se,bag[i-1].se);
        }

        ans += bag[n-1].fi + bag[0].fi;
        r.eb(bag[n-1].se, bag[0].se);

        cout << ans << endl;
        for(auto z : r) cout << z.fi << " " << z.se << endl;
    }

    
    
    return 0;
}

