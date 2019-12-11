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
typedef pair<int,int> ii;
typedef vector<ii> vii;
const ll INF = 1e18;
const double PI = acos(-1.0);
const int T = 1e5 + 3;

vector<int> dvs;
ll v[T];
int n;

ll tent(int sz) {
    vii tmp;
    ll t = 0;
    int mid = 0;
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        if(v[i]) {
            if(t + v[i] <= sz) t += v[i], tmp.eb(i,v[i]);
            else tmp.eb(i,sz-t), t = sz;
            if(t >= sz/2 and mid == 0) mid = i;
        }
        while(t == sz) {
            for(int j = 0; j < tmp.size(); j++)
                ans += abs((ll)mid-(ll)tmp[j].fi)*tmp[j].se;
            ii last = tmp.back();
            tmp.clear();
            t = 0;
            mid = 0;
            if(v[last.fi] - last.se) {
                tmp.eb(last.fi, max(sz, v[last.fi] - last.se));
                t = v[last.fi] - last.se;
                if(t >= sz/2) mid = last.fi;
            }
        }
    }

    cout << sz << " " << ans << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    ll t = 0;

    for(int i = 1; i <= n; i++) cin >> v[i], t += v[i];

    for(ll i = 2; i*i <= t; i++)
        if(!(t % i)) dvs.pb(i), dvs.pb(t/i);
    dvs.pb(t);

    ll ans = INF;
    for(auto x : dvs) ans = min(ans, tent(x));

    cout << (dvs.size() and ans != INF? ans : -1) << endl;
    return 0;
}

