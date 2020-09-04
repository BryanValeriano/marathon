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
const int T = 1e5+3;
ll c[T];

bool cmp(const ii &a, const ii &b) {
    if(a.se != b.se) return a.se > b.se;
    return a.fi < b.fi;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("icecream.in", "r", stdin);
    int tc; cin >> tc;
    while(tc--) {
        int n,k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> c[i];

        vii v;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v.eb(c[i],x);
        }

        sort(v.begin(),v.end());
        int gol = (v[k-1].fi);
        sort(v.begin(),v.end(),cmp);
        ll ans = 0;

        for(int i = 0; i < n and k; i++) {
            if(v[i].fi <= gol) {
                k--;
                ans += (ll)v[i].se;
            }
        }

        cout << gol << " " << ans << endl;
    }
    return 0;
}

