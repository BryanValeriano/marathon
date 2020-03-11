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
const int T = 4e5 + 5;
ll v[T + T + 10];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ll b; cin >> b;
        v[b-i+T] += b;
        ans = max(ans,v[b-i+T]);
    }
    cout << ans << endl;
    return 0;
}

