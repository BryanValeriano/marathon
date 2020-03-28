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

unordered_set<ll> dp[3];
unordered_set<ll> falta;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    dp[0].insert(0);

    bool sol = 0;
    ll ans = -1e18;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        falta.insert(x);
        v.pb(x);
    }


    for(ll x : v) {
        for(int i = 2; i >= 0; i--) {
            for(ll ok : dp[i]) {
                if(i == 2) {
                    if(ok != 0 and falta.count(ok+x))
                        sol = 1, ans = max(ans,ok+x);
                }
                else dp[i+1].insert(ok+x);
            }
        }
    }

    if(sol) cout << ans << endl;
    else cout << "no solution" << endl;
    return 0;
}

