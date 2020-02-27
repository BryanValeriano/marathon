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

ll n,k;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    ll tot = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
        tot += (ll)x;
    }

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    sort(v.begin(), v.end());

    int l = 0;
    int r = n-1;

    ll poor = 1;
    ll rich = 1;
    ll bank = 0;

    while(r-1 >= 0 and bank + rich * (v[r] - v[r-1]) <= k)
        bank += rich * (v[r] - v[r-1]), r--, rich++;
    v[r] -= (k-bank)/rich;

    while(l+1 <= r and k - poor * (v[l+1] - v[l]) >= 0)
        k -= poor * (v[l+1] - v[l]), l++, poor++;

    if(l != r) v[l] += k/poor;
    else {
        cout << (tot%n? 1 : 0) << endl;
        return 0;
    }


    cout << v[r]-v[l] << endl;
    return 0;
}

