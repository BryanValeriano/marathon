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
const ll T = 999999;

int main() {
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    ll aux = 10;
    ll ans = 0;
    for(ll i = 1; i <= min(n,T); i++) {
        if(i >= aux) aux *= 10ll;
        ans += (i+i*aux <= n);
    }
    cout << ans << endl;
    return 0;
}

