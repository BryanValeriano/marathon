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
ll freq[T];
bool dp[2][T];
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;

    while(n--) {
        int x; cin >>x;
        x %= m;
        if(!x) {
            cout << "YES\n";
            return 0;
        }
        freq[x]++;
    }

    for(ll i = 0; i < m; i++) {
        for(ll j = 1; j <= freq[i]; j<<=1) {
            v.pb(i*j%m);
            freq[i] -= j;
        }
        if(freq[i]) v.pb(i*freq[i]%m);
    }

    bool at = 1;

    for(ll x : v) {
        dp[at][x] |= 1;
        for(int i = 0; i < m; i++) dp[at][i] |= dp[!at][(i-x+m)%m];
        for(int i = 0; i < m; i++) dp[at][i] |= dp[!at][i];
        at = !at;
    }

    cout << (dp[!at][0]? "YES" : "NO") << endl;
    return 0;
}

