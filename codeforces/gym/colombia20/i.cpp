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
const int T = 1e5+5;

map<int,vector<int>> patch;
set<ll> le, ri;
ll ans[T];

ll firstDir(ll x) {
    ll r = -1;

    if(!le.empty()) {
        auto iter = le.lower_bound(x);
        if(iter != le.begin()) {
            iter--;
            r = *iter;
        }
    }

    return r;
}

ll firstEsq(ll x) {
    ll r = -1;

    if(!ri.empty()) {
        auto iter = ri.lower_bound(x);
        if(iter != ri.end()) {
            r = *iter;
        }
    }

    return r;
}

ll best(ll x) {
    ll r = 0;

    if(!le.empty()) {
        auto iter = le.lower_bound(x);
        if(iter != le.begin()) {
            iter--;
            r = max(r, x-(*iter) + ans[*iter]);
        }
    }

    if(!ri.empty()) {
        auto iter = ri.lower_bound(x);
        if(iter != ri.end()) {
            r = max(r, (*iter)-x + ans[*iter]);
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        patch[x].pb(i);
    }

    for(map<int,vector<int>>::reverse_iterator it = patch.rbegin(); it != patch.rend(); ++it) {
        for(int x : it->se) ans[x] = best(x);
        int l = INF ,r = 0;
        for(int x : it->se) l = min(l,x), r = max(r,x);
        le.insert(l);
        ri.insert(r);
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

