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
const int K = 22;
int g[K];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("looking.in", "r", stdin);
    int tc; cin >> tc;

    while(tc--) {
        int n,k; cin >> n >> k;
        for(int i = K-1; i >= 0; i--) g[i] = 0;

        while(n--) {
            int x; cin >> x;
            for(int i = 0; (1<<i) <= x; i++) {
                int j = (1<<i);
                if(x&j) g[i] = max(g[i],x);
            }
        }

        int ans = 0;

        for(int i = K-1; i >= 0 and k; i--) {
            int ok = (1<<i);
            if(ans&ok) continue;
            if(!g[i]) continue;
            ans |= g[i];
            k--;
        }

        cout << ans << endl;
    }
    return 0;
}

