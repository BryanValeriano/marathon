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

int main() {
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;
    vector<int> v;
    int cont = 0;

    while(x != -1) {
        v.clear();
        v.pb(0);
        v.pb(x);
        int m = x;
        cin >> x;
        while(x != -1) v.pb(x), m = max(m,x), cin >> x;
        int n = v.size();
        int dp[m+2][n+2];
        memset(dp, 0, sizeof dp);
        int ans = 0;

        for(int i = m; i >= 0; i--) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                if(i == v[j]) dp[i][j]++;
                ans = max(ans,dp[i][j]);
            }
        }

        cout << "Test #" << ++cont << ":\n";
        cout << "  maximum possible interceptions: " << ans << endl;
        cin >> x;
        if(x != -1) cout << endl;
    }

    return 0;
}

