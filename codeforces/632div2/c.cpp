#include <bits/stdc++.h>
using namespace std;

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
const int T = 2e5+5;
map<ll,queue<ll>> pref;
ll v[T], tmp[T];
vii ve;

int main() {
    ios_base::sync_with_stdio(false);
    memset(tmp, INF, sizeof tmp);
    ll n; cin >> n;
    ll sum = 0;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        pref[sum].push(i);
    }

    sum = 0;
    ll ans = (n*(n+1))>>1;

    for(int i = 1; i <= n; i++) {
        if(pref.count(sum) and (!pref[sum].empty())) {
            int low = pref[sum].front();
            ve.eb(i,low);
            tmp[i] = low;
        }
        sum += v[i];
        pref[sum].pop();
    }

    for(int i = n; i >= 1; i--)
        tmp[i] = min(tmp[i],tmp[i+1]);

    ll oldL = 0;
    for(ii x : ve) {
        if(tmp[x.fi+1] > x.se) {
            ans -= (x.fi-oldL)*(n-x.se+1);
            oldL = x.fi;
        }
    }

    cout << ans << endl;
    return 0;
}

