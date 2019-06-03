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
const int MOD = 2000000011;

ll ele(ll base, ll e) {
    ll ans = 1;
    
    while(e) {
        if(e&1) ans = (base * ans) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
       ll x; 
       cin >> x;
       cout << "Case #" << ++cont << ": ";
       if(x <= 2) cout << 1 << endl;
       else cout << ele(x,x-2) << endl;
    }
    return 0;
}

