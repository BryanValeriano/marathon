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
    vector<ll> v;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    }

    ll best = INF;
    for(ll i = 1; i <= 100; i++) {
        ll tmp = 0;
        for(int j = 0; j < n; j++) tmp += abs(i-v[j])*abs(i-v[j]);
        best = min(best,tmp);

    }

    cout << best << endl;

    return 0;
}

