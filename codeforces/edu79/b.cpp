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
const int T = 1e5 + 5;

ll v[T];
vector<ll> sum;
int n;
ll s;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> s;
        sum.clear();
        ll z = 0;
        sum.pb(z);

        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            z += v[i];
            sum.pb(z);
        }

        if(z <= s) { cout << 0 << endl; continue; }
        int ans = 0;
        int x = 1;

        for(int i = 1; i <= n; i++) {
            if(sum[i-1] >= s) break;

            int pos = upper_bound(sum.begin(), sum.end(), s+v[i]) - sum.begin();
            if(pos <= i) continue;

            if(pos == n) {
                ans = max(ans,n-1);
                x = i;
            }
            else if(ans < pos-1) {
                ans = pos-1;
                x = i;
            }
        }

        cout << x << endl;
    }

    return 0;
}

