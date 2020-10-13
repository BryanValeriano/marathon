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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n, ans = 0;
        ll x, sum = 0;
        vector<ll> v;
        cin >> n >> x;

        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            v.pb(tmp);
        }

        sort(v.begin(),v.end(),greater<ll>());
        for(ll i = 0; i < n; i++) {
            sum += v[i];
            if((i+1)*x <= sum) ans = i+1;
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}

