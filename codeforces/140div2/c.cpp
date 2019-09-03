#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

ll n,MOD;

ll ele(ll base, ll e) {
    ll ans = 1;

    while(e) {
        if(e&1) ans = (base * ans) % MOD;
        base = (base*base) % MOD;
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> MOD;

    cout << ((ele(3LL,n) - 1) + MOD) % MOD << endl;

    return 0;
}

