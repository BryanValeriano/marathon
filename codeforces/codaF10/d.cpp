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
const int T = 1e5 + 3;
ll v[T];
int n;

bool check(ll x) {
    ll ok = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] > x) return 0;
        if(ok < x) ok += x-v[i];
    }
    return ok >= x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    ll l = 0;
    ll r = 1e18;
    ll ans = r;
    while(l<=r) {
        ll mid = (l+r)>>1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    cout << ans << endl;
    return 0;
}

