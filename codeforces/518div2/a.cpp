#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    ll ans = (l+k)/m;
    if((l+k) % m != 0) ans++;
    ll ans2 = m*ans;
    if(ans2 > n) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

