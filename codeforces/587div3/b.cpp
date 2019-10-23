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

vector<ii> v;
vector<int> r;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.eb(x,i+1);
    }

    sort(v.begin(),v.end(), greater<ii>());
    ll ans = 0;
    for(ll i = 0; i < n; i++) ans += v[i].fi*i + 1, r.pb(v[i].se);
    cout << ans << endl;
    for(auto ok : r) cout << ok << " ";
    cout << endl;

    
    
    return 0;
}

