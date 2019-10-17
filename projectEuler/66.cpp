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
const int T = 1e7;

ll x,y,d;
unordered_set<ll> sq;

bool ok(ll p) {
    return ((ll)sqrt(p) * (ll)sqrt(p) == p);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    for(ll i = 1; i <= 1000; i++) sq.count(i*i);
    sq.insert(0);
    ll maxi = 0;
    d = 0;

    for(ll b = 1; b <= 1000; b++) {
        if(sq.count(b)) continue;
        for(ll x = sqrt(b); x <= T; x++) {
            if((x*x-1) % b == 0 and ok((x*x-1)/b)) {
                //y = sqrt(((x*x-1)/b));
                //cout << x << " " << y << " " << b << endl;
                if(x > maxi) maxi = x, d = b;
                break;
            }
        }
    }
    
    cout << maxi << " " << d << endl;
    return 0;
}

