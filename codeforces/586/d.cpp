#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 3;

vector<ll> v;
vector<ll> ans;
int d[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    v.pb(0);
    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++)
        for(ll j = v[i]+1; j < T; j += v[i])
            d[j]++;

    for(int i = 1; i <= n; i++) {
        if(v[i] >= n) continue;
        ll last = ((T-1)/v[i])*v[i];
        if(d[last] > 1) {
            ans.pb(v[i]);
            for(ll j = v[i]+v[i]; j < T; j += v[i])
                d[j]--;
        }
    }

    cout << ans.size() << endl;
    for(auto ok : ans) cout << ok << " ";
    if(ans.size()) cout << endl;

    return 0;
}

