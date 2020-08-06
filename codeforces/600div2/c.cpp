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
const int T = 2e5 + 4;
ll v[T];
vector<ll> rest[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);
    for(int i = 0; i < n; i++) {
        int x = i%m;
        ll last = (rest[x].size()? rest[x].back() : 0);
        rest[x].pb(v[i]+last);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll day = (i+1)/m + ((i+1)%m?1:0);
        ans += v[i];
        if(day > 1) ans += rest[i%m][day-2];
        cout << ans << " ";
    }

    cout << endl;

    return 0;
}

