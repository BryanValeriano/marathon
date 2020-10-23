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

ll ele(ll b, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans *= b;
        b *= b;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n,h;
    cin >> n >> h;
    ll ans = 0;
    for(ll i = 1; i <= h; i++)
        ans += ele(i,n-1);
    cout << ans << endl;
    return 0;
}
