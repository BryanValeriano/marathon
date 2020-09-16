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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    vector<ll> v;
    ll sum = 0;

    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        v.pb(x);
        sum += x;
    }

    ll ans = sum;

    sort(v.begin(), v.end());
    for(int i = n-1; i >= 1; i--) {
        if(v[i] > 1) {
            for(int j = 1; j*j <= v[i]; j++) {
                if(v[i]%j) continue;
                ll a = v[i]/j, b = j;

                ll tmp = sum-(v[i]-a);
                tmp += v[0]*b - v[0];
                ans = min(ans,tmp);

                tmp = sum-(v[i]-b);
                tmp += v[0]*a - v[0];
                ans = min(ans,tmp);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

