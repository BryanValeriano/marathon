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
const ll INF = 2e12;

vector<ll> v;
ll n, d;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> d;
    int x;

    for(int i = 0; i < n; i++) {
        cin >> x;
        v.pb(x);
    }

    ll pqp = 1e5;

    v.pb(INF);

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        x = lower_bound(v.begin(), v.end(), v[i]+d) - v.begin();
        while(x > 0 and v[x] > v[i]+d) x--;
        ll y = x-i;
        ll ok = ((y-1) * (y))/2LL;
        ans += ok;
    }
               
    cout << ans << endl;

    return 0;
}

