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

int main() {
    ios_base::sync_with_stdio(false);
    ll n,a,b;
    cin >> n >> a >> b;

    if(a*b >= 6ll*n) {
        cout << a*b << endl;
        cout << a << " " << b << endl;
        return 0;
    }

    bool f = 0;
    if(a > b) swap(a,b),f=1;
    ll ansa = a, ansb = b, best = 1e18;

    for(ll i = a; i*i <= 6ll*n; i++) {
        ll nb = 6ll*n/i;
        if(nb*i < 6ll*n) nb++;
        if(nb < b) break;
        if(i*nb < best) {
            best = i*nb;
            ansa = i;
            ansb = nb;
        }
    }

    if(!f)cout << best << " " << ansa << " " << ansb << endl;
    else cout << best << " " << ansb << " " << ansa << endl;

    return 0;
}

