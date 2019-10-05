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

const int T = 22;
ll dp[T][T];

ll solve(int i, int j) {
    if(i == 20 or j == 20) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = solve(i+1,j) + solve(i,j+1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cout << solve(0,0) << endl;
    return 0;
}

