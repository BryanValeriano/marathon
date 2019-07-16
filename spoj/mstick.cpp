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

const int T = 5e3 + 5;
int dp[T][T];
bool choose[T][T];
ii wl[T];
bool ok[T];
int v;
int n;

int solve(int at, int prev) {
    if(at > n) return 0;
    if(ok[at]) return solve(at+1,prev);
    if(dp[at][prev] != -1) return dp[at][prev];

    int le = 0, re = 0;
    
    if(wl[at].fi >= wl[prev].fi and wl[at].se >= wl[prev].se) re = solve(at+1,at) + 1;
    le = solve(at+1,prev);

    if(re > le) choose[at][prev] = 1;
    return dp[at][prev] = max(re,le);
}

void visit(int at, int prev) {
    if(at > n) return;
    if(ok[at]) return visit(at+1,prev);

    if(choose[at][prev] == 1) {
        ok[at] = 1;
        cout << wl[at].fi << " " << wl[at].se << endl;
        visit(at+1,at);
    } else {
        visit(at+1,prev);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        v++;

        for(int i = 1; i <= n; i++)
            cin >> wl[i].fi >> wl[i].se;

        sort(wl+1, wl+n+1);

        memset(ok, 0, sizeof ok);
        memset(choose, 0, sizeof choose);
        memset(dp,-1,sizeof dp);

        int ans = 0;
        while(solve(1,0)) {
            ans++;
            visit(1,0);
            cout << endl;
            memset(dp,-1,sizeof dp);
        }

        cout << ans << endl;
    }

    return 0;
}

