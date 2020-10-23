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

bool corn(ll k, ll x) {
    if(k < 0 or (k&1)) return false;
    k >>= 1;

    for(ll i = 1; i <= x; i<<=1) {
        if((k&i) and (x&i)) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll s,x,k;
    cin >> s >> x;
    k = s-x;


    if(!corn(k,x)) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = (1ll<<(__builtin_popcountll(x))) - (k? 0 : 2);
    cout << max(0ll,ans) << endl;
    return 0;
}

