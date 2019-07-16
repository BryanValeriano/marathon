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

const int T = 110;

ll qtd[T];
ll price[T];
ll dp[T][T];
ll vis[T][T];
int t, n;

ll solve(int at, int last) {
    if(at == n) return ((qtd[at] - qtd[last] + 10) * price[at]);
    if(vis[at][last] == t) return dp[at][last];
    vis[at][last] = t;
    return dp[at][last] = min(solve(at+1,last), solve(at+1,at) + ((qtd[at] - qtd[last] + 10) * price[at]));
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        t++;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> qtd[i] >> price[i];
        for(int i = 1; i <= n; i++) qtd[i] += qtd[i-1];
        cout << solve(0,0) << endl;
    }
    return 0;
}

