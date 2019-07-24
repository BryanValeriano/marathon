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

const int T = 37;
ll v[T];

int main() {
    ios::sync_with_stdio(false);

    for(ll i = 0; i < 37; i++) v[i] = pow(3LL,i);
    ll n; cin >> n;
    
    ll ans = 0;

    for(int i = 1; i < 37; i++) 
        if(n % v[i]) { ans = n/v[i]; break; }

    cout << ans+1 << endl;

    return 0;
}

