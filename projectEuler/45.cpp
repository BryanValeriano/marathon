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

ll tri(ll x) {
    return (x*(x+1)>>1);
}

ll p(ll x) {
    return (x*(3*x-1)>>1);
}

ll h(ll x) {
    return (x*(2*x-1));
}

bool check(ll a, bool op, ll x) {
    return (op? p(a) >= x : h(a) >= x);
}

bool bin(ll x, bool op) {
    ll l = 0;
    ll r = 1e5;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid,op,x)) r = mid-1;
        else l = mid+1;
    }

    return (op? p(l) == x : h(l) == x);
}

bool ok(ll i) {
    i = tri(i);
    return (bin(i,0)? bin(i,1) : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll i = 286;
    for(; !ok(i); i++);
    cout << tri(i) << endl;
    return 0;
}

