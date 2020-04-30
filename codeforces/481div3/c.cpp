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
const int T = 2e5 + 3;
vector<ll> v(T);
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i], v[i]+=v[i-1];
    while(m--) {
        ll x; cin >> x;
        int l = 0;
        int r = n;
        int ans = 0;
        while(l <= r) {
            int mid = (l+r)>>1;
            if(v[mid] >= x) ans = mid, r = mid-1;
            else l = mid+1;
        }
        cout << ans << " " << x-(ans?v[ans-1]:0) << endl;
    }
    return 0;
}

