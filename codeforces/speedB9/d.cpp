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

vector<ll> v;
 
int main() {
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(),v.end(), greater<ll>());

    ll x = 0;
    ll z = n;
    while(z) x++, z/= 4;

    ll qtd = 1;
    int at = 0;
    ll ans = 0;

    while(at < n) {
        ans += v[at]*x;
        at++;
        if(at == qtd) {
            qtd *= 4ll;
            x--;
        }
    }
    
    cout << ans << endl;
    return 0;
}

