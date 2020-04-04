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
const int T = 5e5 + 3;
vii stk;
int n,m;

int bb(int at, ll aux) {
    int l = 0;
    int r = stk.size()-1;
    int ans = INF;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(stk[mid].se+aux >= m) ans = mid, l = mid+1;
        else r = mid-1;
    }

    if(ans != INF) return (at-stk[ans].fi+1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        int ans = INF;
        ll aux = 0;
        stk.clear();
        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            while(!stk.empty() and stk.back().se+aux+x <= x) stk.pop_back();
            stk.eb(i,-aux);
            aux += x;
            ans = min(ans, bb(i,aux));
        }
        cout << (ans==INF?-1:ans) << endl;
    }
    return 0;
}

