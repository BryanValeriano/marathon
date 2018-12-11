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
int memo[32][32][52];

int solve(int n, int m, int k) {
    if(k == 0) return 0;
    if(n*m == k) return 0;
    if(n*m < k) return INF;

    int &r = memo[n][m][k];
    if(r != -1) return r;
    int ans = INF;

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= k; j++)
            ans = min(ans, m*m + solve(n-i, m, k-j) + solve(i,m,j));

    for(int i = 1; i < m; i++)
        for(int j = 0; j <= k; j++)
            ans = min(ans, n*n + solve(n, m-i, k-j) + solve(n,i,j));

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    memset(memo, -1, sizeof memo);
    while(tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n,m,k) << endl;
    }
    return 0;
}

