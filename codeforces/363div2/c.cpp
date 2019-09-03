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

const int T = 105;
int v[T];
int dp[T][3];
int n;

int solve(int at, int last) {
    if(at == n) return 0;
    if(dp[at][last] != -1) return dp[at][last];

    int ans = INF;

    if(v[at] == 0) ans = solve(at+1,0) + 1;
    else if(v[at] == 1) {
        if(last != 1) ans = min(ans,solve(at+1,1));
        ans = min(ans,solve(at+1,0) + 1);
    }
    else if(v[at] == 2) {
        if(last != 2) ans = min(ans,solve(at+1,2));
        ans = min(ans,solve(at+1,0) + 1);
    } else {
        if(last != 2) ans = min(ans,solve(at+1,2));
        if(last != 1) ans = min(ans,solve(at+1,1));
    }

    return dp[at][last] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << solve(0,0) << endl;
    return 0;
}

