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

const int T = 32;
int dp[T];
int n,p,w,v,ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    while(n) {
        cin >> p;
        ans = 0;
        memset(dp,0,sizeof dp);
        for(int i = 0; i < n; i++) {
            cin >> v >> w;
            for(int j = p; j-w >= 0; j--) {
                dp[j] = max(dp[j], dp[j-w]+v);
                ans = max(ans,dp[j]);
            }
        }
        cout << ans << " min." << endl;
        cin >> n;
    }
    return 0;
}

