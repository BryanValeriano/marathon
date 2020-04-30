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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e5 + 10;
ll v[T];
ll nv[T];
int n,r;
ll k;

bool check(__int128 x) {
    memset(nv,0,sizeof nv);
    ll cost = 0;
    ll kk = k;

    for(int i = 1; i <= n and cost <= kk; i++) {
        nv[i] += nv[i-1];
        ll y = (x-v[i] > nv[i]? x-v[i]-nv[i]: 0);
        nv[i] += y;
        nv[min(n+1,i+2*r+1)] -= y;
        cost += y;
    }

    return (cost <= kk);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> r >> k;

    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        v[max(1,i-r)] += x;
        v[min(n+1,i+r+1)] -= x;
    }
    for(int i = 1; i <= n; i++) v[i] += v[i-1];

    ll l = 0;
    ll ans = 0;
    ll r = 2e18;

    while(l <= r) {
        ll mid = (l+r)>>1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;

    return 0;
}

