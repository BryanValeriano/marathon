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
const ll INF = 2e18;
const int T = 38;
vector<ll> v[2];
vector<ll> bag[2];
int t[2];

void subs(int at, int pos, ll sum) {
    if(at == t[pos]) { 
        if(sum == 0) { if(pos != 1) bag[pos].pb(sum); }
        else bag[pos].pb(sum);
        return;
    }
    subs(at+1,pos,sum); 
    subs(at+1,pos,sum+v[pos][at]);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll x = 1;
    for(int i = 0; i <= T; i++) {
        v[(i >= 18)].pb(x);
        x *= 3ll;
    }
    t[0] = v[0].size();
    t[1] = v[1].size();
    subs(0,1,0);
    subs(0,0,0);

    sort(bag[0].begin(), bag[0].end());
    sort(bag[1].begin(), bag[1].end());
    for(int i = 0; i < 20; i++) {
        cout << bag[0][i] << endl;
    }
    int tc; cin >> tc;

    while(tc--) {
        ll z; cin >> z;
        ll best = INF;
        if(z <= *bag[1].begin()) {
            ll y = lower_bound(bag[0].begin(), bag[0].end(), z) - bag[0].begin(); 
            if(y < bag[0].size() and bag[0][y] >= z) cout << bag[0][y] << endl;
            else cout << *bag[1].begin() << endl;
        } else {
            for(ll ok : bag[0]) {
                ll y = lower_bound(bag[1].begin(), bag[1].end(), z-ok) - bag[1].begin();
                if(y < bag[1].size()) best = min(best,bag[1][y]+ok-z);
            }
            cout << z+best << endl;
        }
    }

    return 0;
}

