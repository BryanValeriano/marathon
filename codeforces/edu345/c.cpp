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

set<ii> vis;
vector<ii> rep;
unordered_map<int,ll> x;
unordered_map<int,ll> y;


int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a,b;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(vis.count(ii(a,b))) rep.pb(ii(a,b)); 
        else vis.insert(ii(a,b));
        x[a]++;
        y[b]++;
    }

    for(auto z : x) if(z.se > 1) ans += (z.se * (z.se-1)) >> 1;
    for(auto z : y) if(z.se > 1) ans += (z.se * (z.se-1)) >> 1;

    sort(rep.begin(), rep.end());
    ll t = (rep.size()? 1 : 0);
    for(int i = 1; i < rep.size(); i++) {
        if(rep[i] == rep[i-1]) t++;
        else ans -= (t*(t+1)) >> 1, t = 1;
    }

    ans -= (t*(t+1)) >> 1;
    cout << ans << endl;

    return 0;
}

