#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
int dp[2][3];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j  < 3; j++) cin >> dp[1][j];
        dp[1][0] += max(dp[0][1],dp[0][2]);
        dp[1][1] += max(dp[0][0],dp[0][2]);
        dp[1][2] += max(dp[0][1],dp[0][0]);
        for(int j = 0; j < 3; j++) dp[0][j] = dp[1][j];
    }
    cout << max({dp[0][0],dp[0][1],dp[0][2]}) << endl;
    return 0;
}

