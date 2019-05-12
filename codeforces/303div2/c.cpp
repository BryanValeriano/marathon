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

const int T = 1e5 + 10;
vector<int> v;
vector<int> h;
int dp[T][2];
int n;

int solve(int at, int tras) {
    if(at >= n) return 0;
    if(dp[at][tras] != -1) return dp[at][tras];

    int ans = 0;
    if(at == n-1 or v[at+1] > v[at] + h[at]) ans = solve(at+1, (v[at+1] - h[at+1] > v[at] + h[at]? 1 : 0)) + 1;
    if(at+1 < n and tras) ans = max(ans, solve(at+1, (v[at] < v[at+1] - h[at+1]? 1 : 0)) + 1);
    else if(at+1 < n) ans = max(ans, solve(at+1, (v[at] < v[at+1] - h[at+1]? 1 : 0)));

    return dp[at][tras] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n;
    int x,y;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.pb(x);
        h.pb(y);
    }

    cout << solve(0,1) << endl;

    return 0;
}

