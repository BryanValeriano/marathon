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

ll calc(ll x) {
    return (x*(x+1))>>1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll n,m;
        cin >> n >> m;
        ll ans = calc(n);

        if(m == 0) cout << 0 << endl;
        else if(m >= n/2) cout << ans - (n-m) << endl;
        else {

            ll rest1 = n-m;
            ll rest2 = rest1/(m+1);
            ll c1 = rest1%(m+1);
            ll c2 = (m+1) - c1;
            rest1 = rest2+1;

            //cout << c1 << " * " << rest1 << " " << c2 << " * " << rest2 << endl;
            cout << ans - calc(rest1)*c1 - calc(rest2)*c2 << endl;
        }

    }
    return 0;
}

