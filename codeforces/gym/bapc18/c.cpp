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

void find_div(int x, vector<ll> &v) {
    for(int i = 1; i*i <= x; i++) {
        if(x%i == 0) v.pb(i), v.pb(x/i);
    }
}

ll surface_area(ll a, ll b, ll c) {
    return 2*a*b + 2*a*c + 2*b*c;
}
 
int main() {
    ios_base::sync_with_stdio(false);

    ll V; cin >>V;
    vector<ll> vs;
    find_div(V, vs);

    ll ans = LLONG_MAX;
    for(auto v:vs){
        vector<ll> ts;
        find_div(V/v, ts);
        for(auto t:ts) {
            if(V%(v*t) == 0 and V/(v*t) > 0) {
                ans = min(ans, surface_area(v, t, V/(v*t)));
            }
        }
    }

    cout <<ans <<endl;
    
    return 0;
}

