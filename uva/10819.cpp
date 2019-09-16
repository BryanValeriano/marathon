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
    string r;

    while(~scanf("%d %d", &t, &n)) {
        int last = t;

        if(t > 1800) t += 200;
        vez++; vis[0] = vez;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &sz[i], &ganho[i]);
            for(int j = t; j-sz[i] >= 0; j--) {
                if(vis[j-sz[i]] == vez) {
                    if(vis[j] != vez) dp[j] = 0;
                    dp[j] = max(dp[j], ganho[i] + dp[j-sz[i]]), vis[j] = vez;
                    if(j > last and j <= 2000) continue;
                    ans = max(ans,dp[j]);
                }
            }
        }
        r += to_string(ans) + "\n";
    }

    printf("%s", r.c_str());

    return 0;
}

