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
const int T = 3e3+5;
const ll MOD = 998244353;
ll dp[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,s; cin >> n >> s;
    dp[0] = 1;
    for(int k = 1; k <= n; k++) {
        int x; cin >> x;
        for(int i = s; i-x >= 0; i--) {
            dp[i] = (dp[i] + dp[i-x]) % MOD;
        }
    }
    cout << dp[s] << endl;
    return 0;
}

