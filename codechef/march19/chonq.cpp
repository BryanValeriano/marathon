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

const int T = 2e5 + 4;
int v[T];
ll acum[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> v[i];
        reverse(v+1, v+n+1);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= v[i]; j++) {
                if(v[i] / j != j) {
                    acum[i + j - 1] += v[i]/j;
                    acum[i + j] -= v[i]/j;
                }
                int high = v[i]/j; int low = v[i]/(j+1);
                acum[i + low] += j; acum[i + high] -= j;
            }
        }

        for(int i = 1; i <= n; i++) acum[i] += acum[i-1];

        reverse(acum+1, acum+n+1);
        int ans = n+1;
        for(int i = 1; i <= n; i++) {
            if(acum[i] <= k) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
        memset(v, 0, sizeof v);
        memset(acum, 0, sizeof acum);
    }
    return 0;
}

