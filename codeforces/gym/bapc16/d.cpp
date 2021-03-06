#include <bits/stdc++.h>
using namespace std;

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
const int T = 4e3+2;
int t[T], dp[T];

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,INF,sizeof dp);
    int n; cin >> n;
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        for(int k = 1; k <= i; k++)
            dp[i] = min(dp[i], dp[i-k] + max(t[i]-t[i-k+1]-1800+20,20*k)+120);
        cout << dp[i] << endl;
    }

    cout << dp[n] << endl;
    return 0;
}

