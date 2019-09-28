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

bool ok(ll x) {
    vector<int> v;
    while(x) {
        v.pb(x%10);
        x /= 10;
    }
    vector<int> vv = v;
    reverse(v.begin(),v.end());
    return (vv == v);
}
 
int main() {
    ios_base::sync_with_stdio(false);

    ll ans = 0;

    for(ll i = 100; i < 1000; i++) 
        for(ll j = i+1; j < 1000; j++) 
            if(ok(i*j)) ans = max(ans,i*j);

    cout << ans << endl; 
    return 0;
}

