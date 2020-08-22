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
const int T = 52;
int v[T];
bool vis[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        int ans = 0;

        for(int i = 1; i <= 100; i++) {
            memset(vis, 0, sizeof vis);
            int ok = 0;
            for(int j = 0; j < n; j++) {
                if(vis[j]) continue;
                for(int k = j+1; k < n; k++) {
                    if(vis[k]) continue;
                    if(v[j]+v[k]==i) {
                        vis[j] = vis[k] = 1;
                        ok++;
                        break;
                    }
                }
            }
            ans = max(ans,ok);
        }

        cout << ans << endl;
    }
    return 0;
}

