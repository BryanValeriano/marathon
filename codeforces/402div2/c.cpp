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

const int T = 2e5 + 3;
ll a[T];
ll b[T];

bool vis[T];
vii v;
int n, k;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) v.eb(a[i]-b[i],i);

    sort(v.begin(), v.end());
    ll ans = 0;

    for(int i = 0; i < n; i++) 
        if(i < k or v[i].fi < 0) ans += a[v[i].se], vis[v[i].se] = 1; 
        

    for(int i = 0; i < n; i++) if(!vis[i]) ans += b[i];
    cout << ans << endl;
    
    
    return 0;
}

