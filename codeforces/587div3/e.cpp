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

bool check(ll x, ll k) {
    return ((x*(x+1)) >> 1) >= k;
}

int bin(ll k) {
    ll l = 0;
    ll r = 1e9;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid,k)) r = mid-1;
        else l = mid+1;
    }
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll k;
        cin >> k;
        cout << bin(k) << endl;
    }
    return 0;
}

