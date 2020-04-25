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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5 + 3;

vii v;;
int n;

ll check(ll t) {
    if(t <= 0) return 0;
    t = min(t,(ll)n);
    ll sum = 0;
    vii ok;

    for(int i = 0; i < t; i++) ok.eb(v[i].se,v[i].fi);
    sort(ok.begin(),ok.end());

    for(ll i = 0; i < t; i++) {
        sum += (ll)ok[i].se-(i+1ll);
        if(sum < 0) return t*-INF;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {;
        int x; cin >> x;
        v.eb(x,i);
    }

    sort(v.begin(),v.end(),greater<ii>());

    int l = -1;
    int r = n;
    while(r-l >1) {
        int mid = (l+r) >> 1;
        if(check(mid) > check(mid+1)) r = mid;
        else l = mid;
    }
    ll ans = 0;
    for(int i = l-5; i <= l+5; i++) ans = max(ans,check(i));
    cout << ans << endl;
    return 0;
}
