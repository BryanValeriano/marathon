#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 5;

vector<ll> bag;
vii ve;
ll v[T];
ll ans;

int main() {
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    int x, y;

    for(int i = 0; i < n; i++) {
        cin >> x;
        bag.pb(x);
    }

    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        v[x]++, v[y+1]--;
    }

    for(int i = 1; i <= n; i++) {
        v[i] += v[i-1];
        ve.eb(v[i], i);
    }

    sort(ve.begin(), ve.end(), greater<ii>());
    sort(bag.begin(), bag.end(), greater<int>());
    
    for(int i = 0; i < bag.size(); i++) 
        ans += ve[i].fi * bag[i];

    cout << ans << endl;

    return 0;
}

