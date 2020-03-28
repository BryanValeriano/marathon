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
const int Z = 4e2 + 10;
int n, ma,mb;
int dp[Z][Z];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> ma >> mb;

    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;
    while(n--) {
        int a,b,c; cin >> a >> b >> c;
        for(int j = Z-1; j-a >= 0; j--)
            for(int k = Z-1; k-b >= 0; k--) {
                dp[j][k] = min(dp[j][k], dp[j-a][k-b]+c);
            }
    }

    int ans = INF;
    for(int i = 1; i*ma < Z and i*mb < Z; i++) ans = min(ans,dp[i*ma][i*mb]);
    cout << (ans == INF? -1 : ans) << endl;
    return 0;
}

