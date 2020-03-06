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

vii v[2];
int n[2];
int d;

int bb(ll t) {
    int l = 0;
    int r = v[1].size()-1;
    int ans = 0;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(t + v[1][mid].se <= d) ans = mid, l = mid+1;
        else r = mid-1;
    }

    return ans;
}

bool cmp(const ii &a, const ii &b) {
    if(a.fi != b.fi) return a.fi > b.fi;
    if(a.se != b.se) return a.se < b.se;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n[0] >> n[1] >> d;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n[i]; j++) {
            int a,b; cin >> a >> b;
            v[i].eb(a,b);
        }

    sort(v[0].begin(),v[0].end(),cmp);
    sort(v[1].begin(),v[1].end(),cmp);

    for(int i = 0; i < 2; i++)
        for(int j = 1; j < n[i]; j++) {
            v[i][j].fi += v[i][j-1].fi;
            v[i][j].se += v[i][j-1].se;
        }

    ll ans = 0;

    for(int i = 0; i < n[0]; i++) {
        int pos = bb(v[0][i].se);
        if(v[0][i].se + v[1][pos].se <= d) ans = max(ans,v[0][i].fi + v[1][pos].fi);
    }

    cout << ans << endl;

    return 0;
}
;
