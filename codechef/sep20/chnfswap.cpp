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
ll gol;
ll n;

bool check(ll x) {
    ll tmp = (x*(x+1))>>1;
    ll mini = gol-tmp+1;
    return mini <= n;
}

ll calc(ll x) {
    ll tmp = (x*(x+1))>>1;
    ll maxi = gol-tmp+x;
    ll mini = gol-tmp+1;
    return max(0ll,min(n+1,maxi+1)-max(mini,x+1));
}

ll hasEq() {
    ll l = 1;
    ll r = n;
    ll ans = -1;

    while(l <= r) {
        ll mid = (l+r)>>1;
        ll tmp = mid*(mid+1)>>1;
        if(tmp > gol) r = mid-1;
        else if(tmp == gol) { ans = mid; break; }
        else l = mid+1;
    }

    if(ans != -1) {
        ll a = ans;
        ll b = n-ans;
        return (a*(a-1)>>1)+(b*(b-1)>>1);
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        if(n <= 4) {
            cout << (n <= 2? 0 : 2) << endl;
            continue;
        }

        gol = (n*(n+1))>>1;
        if(gol&1) {
            cout << 0 << endl;
            continue;
        }

        gol >>= 1;

        ll l = 2;
        ll ans = 1;
        ll r = n;

        while(l <= r) {
            ll mid = (l+r)>>1;
            if(check(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }

        ll resp = 0;
        for(ll i = ans; i < ans+5; i++)
            resp += calc(i);

        resp += hasEq();
        cout << resp << endl;
    }

    return 0;
}

