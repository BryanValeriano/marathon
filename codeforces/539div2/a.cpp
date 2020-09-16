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
    ll n,c; cin >> n >> c;
    ll f = min(n-1,c);
    ll ans = f;
    for(ll i = 2; i <= n; i++) {
        f--;
        if(i+f < n) ans += i, f++;
    }
    cout << ans << endl;
    return 0;
}

