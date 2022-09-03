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
const ll MOD = 998244353;
const int T = 1e3+5;
ll dp[T];
ll choose[T][T];
ll v[T];

void pre() {
    for(int i = 0; i < T; i++) {
        choose[i][0] = 1;
        choose[i][i] = 1;
    }
    for(int i = 1; i < T; i++)
        for(int j = 1; j < T; j++)
            choose[i][j] = (choose[i-1][j-1]+choose[i-1][j])%MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
    pre();
    int n; cin >> n;
    ll ans = 0;

    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int i = n-1; i >= 1; i--) {
        if(i+v[i] <= n && v[i] > 0) {
            dp[i] = choose[n-i][v[i]];
            for(int j = i+v[i]; j <= n; j++) {
                dp[i] = (dp[i]+((choose[j-i][v[i]] * dp[j+1])%MOD))%MOD;
            }
        }
        ans = (ans+dp[i])%MOD;
    }
    cout << ans << endl;
    return 0;
}

