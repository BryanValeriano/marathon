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
const int T = 1e6+3;
const int N = 42;
bitset<T> bit[N];
bitset<T> my;
vector<ll> v;
int n,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    vector<ll> ve(n);
    for(int i = 0; i < n; i++) cin >> ve[i];

    for(int i = 0; i < n; i++) {
        ll sum = 0;
        for(int j = i; j < n; j++) {
            sum += ve[j];
            v.pb(sum);
        }
    }

    for(int i = 0; i < v.size(); i++) {
        ll x = v[i];
        for(ll j = 1, casa = 0; j <= x; j <<= 1, casa++)
            if(x&j) bit[casa][i] = 1;
    }

    ll ans = 0;
    my.set();

    for(int ok = N-1; ok >= 0; ok--) {
        if(bit[ok].count() >= k) {
            bitset<T> tmp = my&bit[ok];
            if(tmp.count() >= k) {
                ans += (1ll << ok);
                my &= bit[ok];
            }
        }
    }

    cout << ans << endl;

    return 0;
}

