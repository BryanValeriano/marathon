#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll dist[33];
    vector<ll> v;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    for(int i = 0; i < 33; i++) dist[i] = (1ll << i);

    sort(v.begin(),v.end());
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 33; k++) {
            vector<int> tmp;
            tmp.pb(v[i]);

            for(ll j = dist[k]; j <= dist[k]*2; j += dist[k])
                if(binary_search(v.begin(),v.end(),v[i]+j)) tmp.pb(v[i]+j);

            if(tmp.size() > ans.size()) ans = tmp;
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

