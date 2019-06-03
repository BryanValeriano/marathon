#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int n, s;
vii v;

bool check(int x, int op) {
    sort(v.begin(), v.end(), [&] (const ii &a, const ii &b) {
        return(a.fi + a.se*x < b.fi + b.se*x);
    });

    ll ans = 0;
    for(int i = 0; i < x; i++) ans += v[i].fi + v[i].se*x;

    if(op) cout << ans << endl;
    return (ans <= s);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int x;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        v.eb(x,i);
    }

    int l = 0;
    int r = n;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid,0)) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << " ";
    check(r,1);
    return 0;
}

