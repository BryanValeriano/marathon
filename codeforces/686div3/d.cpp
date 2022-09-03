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
        ll n; cin >> n;
        vector<ll> ans;
        for(ll i = 2; i*i <= n; i++) {
            int sz = 1;
            while(!(n%i)) {
                if(sz > ans.size()) ans.pb(1);
                ans[sz-1]*=i;
                sz++;
                n /= i;
            }
        }
        if(n > 1) {
            int sz = 1;
            if(sz > ans.size()) ans.pb(1);
            ans[sz-1]*=n;
        }
        cout << ans.size() << endl;
        for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

