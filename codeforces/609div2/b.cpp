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
const int T = 2e3+3;
ll a[T],b[T],c[T],n,m;

ll possible(ll x) {
    x %= m;
    x = (x+m)%m;
    for(int i = 0; i < n; i++) c[i] = (a[i]+x)%m;
    sort(c,c+n);
    for(int i = 0; i < n; i++)
        if(c[i] != b[i])
            return INF;

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(b,b+n);
    ll ans = INF;
    for(int i = 0; i < n; i++)
        ans = min(ans, possible(b[i]-a[0]));
    cout << ans << endl;
    return 0;
}

