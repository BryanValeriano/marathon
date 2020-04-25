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
const int T = 2e5 + 3;
vector<ll> v(T);
ll n,t;

ll cost(ll a, ll b) {
    a = v[a], b = v[b];
    if(a <= 0 and b <= 0) return abs(a);
    if(a >= 0 and b >= 0) return b;
    return min(b,abs(a))*2 + max(abs(a),b);
}

bool check(int x) {
    for(int i = 0; i+x-1 < n; i++)
        if(cost(i,i+x-1) <= t) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0;
    int r = n;
    int ans = 0;

    check(5);

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;

    return 0;
}

