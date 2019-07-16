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

const int T = 1e5 + 5;
ll dp[T][2][2];
vector<int> pos[T];
int n;

ll solve(int at, int a, int b) {
    if(at > n) return 0;
    if(dp[at][a][b] != -1) return dp[at][a][b];

    ll a0 = abs(pos[at-1][a] - pos[at][0]);
    ll a1 = abs(pos[at-1][a] - pos[at][1]);
    ll b0 = abs(pos[at-1][b] - pos[at][0]);
    ll b1 = abs(pos[at-1][b] - pos[at][1]);

    dp[at][a][b] = min(solve(at+1, 1, 0) + a1 + b0, solve(at+1, 0, 1) + a0 + b1);

    return dp[at][a][b];
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n;
    int x;

    for(int i = 0; i < 2*n; i++) {
        cin >> x;
        pos[x].pb(i);
    }

    ll ini = pos[1][0] + pos[1][1];

    cout << min(solve(2,0,1) , solve(2,1,0)) + ini << endl;

    return 0;
}

