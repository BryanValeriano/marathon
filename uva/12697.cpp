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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e5 +3;

set<int> bag;
vii p;
ll v[T];
int n;
ll x;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> x;
        p.clear();
        bag.clear();

        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            v[i] += v[i-1];
            p.eb(v[i],i);
        }
        p.eb(0,0);

        sort(p.begin(), p.end());
        int point = 0;
        ll ans = INF;

        for(auto pi : p) {
            ll up = pi.fi-x;

            while(point < n and p[point].fi <= up)
                bag.insert(p[point++].se);

            if(bag.size()) {
                auto best = bag.lower_bound(pi.se);
                if(best == bag.end()) best--;
                while(best != bag.begin() and *best >= pi.se) best--;
                if(*best < pi.se) {
                    ans = min(ans, pi.se-(*best));
                }

            }
        }

        cout << (ans == INF? -1 : ans) << endl;
    }
    return 0;
}

