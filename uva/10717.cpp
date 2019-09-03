#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

ll coins[52];
vector<ll> lcm;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    while(n or m) {
        for(int i = 0; i < n; i++) cin >> coins[i];
        lcm.clear();

        for(int i = 0; i+3 < n; i++) { 
            ll z = coins[i];
            for(int j = i+1; j+2 < n; j++) {
                ll x = (z*coins[j])/__gcd(z,coins[j]);
                for(int k = j+1; k+1 < n; k++) {
                    ll y = (x*coins[k])/__gcd(x, coins[k]);
                    for(int p = k+1; p < n; p++) {
                        ll w = (y*coins[p])/__gcd(y, coins[p]);
                        lcm.pb(w);
                    }
                }
            }
        }
        ll ans,ans2,x,z;
        while(m--) {
            cin >> x;
            ans = 0;
            ans2 = ((x)/lcm[0]) * lcm[0] + lcm[0];
            for(int i = 0; i < lcm.size(); i++) { 
                z = (x/lcm[i]) * lcm[i];
                ans = max(ans,z);
                if(z < x) z += lcm[i];
                ans2 = min(ans2,z);
            }
            cout << ans << " " << ans2 << endl;
        }
        cin >> n >> m;
    }

    return 0;
}

