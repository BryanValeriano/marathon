#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 5;
ll v[T];
ll n,p,q;

bool check(ll x) {
    ll pp = 0;
    for(int i = 0; i < n; i++) {
        ll z = v[i] - (x*q);
        if(z > 0) {
            if(!(p-q)) return 0;
            pp += z/(p-q) + (z % (p-q)? 1 : 0);
        }
    }
    return pp <= x;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> q;
    for(int i = 0; i < n; i++) cin >> v[i];

    ll l = 0;
    ll r = 1e9 + 10;
    ll ans = r;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans << endl; 
    
    return 0;
}

