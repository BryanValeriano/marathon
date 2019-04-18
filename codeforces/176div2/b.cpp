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

ll n,k;

bool can(ll tent) {
    ll x = (k * (k+1)) / 2;
    x -= ((k-tent) * (k-tent+1))/2;
    x -= tent-1;
    return x >= n;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if(n == 1) { cout << 0 << endl; return 0; }
   

    ll l = 0; 
    ll r = k;

    while(l <= r) { 
        ll mid = (l+r) >> 1;
        if(can(mid)) r = mid - 1;
        else l = mid + 1;
    }
    
    if(!can(l)) cout << -1 << endl;
    else if(l == 0) cout << 1 << endl;
    else cout << l << endl;

    return 0;
}

