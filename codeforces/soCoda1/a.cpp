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
const int T = 103;

int n;
int i = 0;
int mov [4][2][2]  = { { {1,0}, {1,-1} },  { {0,-1}, {1,0} }, { {1,0}, {1,1} }, { {1,0}, {0,1} } };
int dp[T][6];
string s[2];

bool isIn(int x, int y) {
    return (x >= 0 and x <= 1 and y >= 0 and y < n);
}

int solve(int at, int last) {
    if(at >= n) return 0;
    if(dp[at][last] != -1) return dp[at][last];

    dp[at][last] = solve(at+1,0);

    int j = at;

    for(int t = 0; t < 4; t++) {
        if(s[i][j] == 'X') break;
        bool f = 1;

        for(int k = 0; k < 2; k++) {
            int ii = i + mov[t][k][0];
            int jj = j + mov[t][k][1];
            if(!isIn(ii,jj) or s[ii][jj] == 'X') f = 0;
        }

        if(!f) continue;

        s[i][j] = 'X';
        for(int k = 0; k < 2; k++) {
            int ii = i + mov[t][k][0];
            int jj = j + mov[t][k][1];
            s[ii][jj] = 'X';
        }

        dp[at][last] = max(dp[at][last], solve(at + (t > 1? 2 : 1), t+1)+1);

        s[i][j] = '0';
        for(int k = 0; k < 2; k++) {
            int ii = i + mov[t][k][0];
            int jj = j + mov[t][k][1];
            s[ii][jj] = '0';
        }

    }

    return dp[at][last];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s[0] >> s[1];
    memset(dp,-1,sizeof dp);
    n = s[0].size();
    int ans = solve(0,0);
    cout << ans << endl;
    return 0;
}

