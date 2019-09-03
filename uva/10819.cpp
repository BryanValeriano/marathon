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

const int T = 10202;
const int N = 102;

int dp[T];
int vis[T];
int sz[N];
int ganho[N];
int vez,t,n;
bool flag;

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> t >> n) {
        if(t < 2000) flag = 1;
        else flag = 0;

        if(t > 1800) t += 200;
        memset(dp, 0, sizeof dp);
        vez++; vis[0] = vez;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            cin >> sz[i] >> ganho[i];
            for(int j = t; j-sz[i] >= 0; j--) {
                if(vis[j-sz[i]] == vez) {
                    dp[j] = max(dp[j], ganho[i] + dp[j-sz[i]]), vis[j] = vez;
                    if(j == 2000 and flag) continue;
                    //cout << i << " " << j << " " << dp[j] << endl;
                    ans = max(ans,dp[j]);
                }
            }
        }

        cout << ans << endl;
    }

    cout << endl;

    return 0;
}

