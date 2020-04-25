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
const int T = 2e5 + 3;
ll le[T];
ll ri[T];
ii be[T];
int n,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> ri[i], ri[i] += ri[i-1];
    for(int i = n; i >= k+1; i--) {
        le[i] = ri[i]-ri[i-1], le[i] += le[i+1];
        be[i] = mk(0,0);
        if(i+k-1 <= n) {
            if(le[i] >= be[i+1].fi) be[i] = mk(le[i],i);
            else be[i] = be[i+1];
            le[i] -= ri[i+k-1]-ri[i+k-2];
        }
    }

    ll ans = 0;
    int a,b;
    for(int i = k; i+k <= n; i++) {
        ll x = ri[i]-ri[i-k] + be[i+1].fi;
        if(x > ans) {
            ans = x;
            a = i-k+1; b = be[i+1].se;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}

