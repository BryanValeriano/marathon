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

const int T = 2e5 + 5;
ll dp[2][T];
ll a[T];
ll b[T];
ll c;
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> c;

    for(int i = 2; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++) cin >> b[i];
    cout << 0 << " ";

    dp[1][1] = c;

    for(int i = 2; i <= n; i++) {
        dp[0][i] = min(dp[0][i-1] + a[i], dp[1][i-1] + a[i]);
        dp[1][i] = min({dp[0][i-1] + c + b[i], dp[1][i-1] + b[i]});
        cout << min(dp[0][i],dp[1][i]) << " ";
    }
    
    cout << endl;
    
    return 0;
}

