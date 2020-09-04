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
const int T = 102;

long double dp[T][T];

void pre() {
    for(int i = 0; i < T; i++)
        dp[i][0] = dp[i][i] = 1;

    for(int i = 1; i < T; i++)
        for(int j = 1; j < T; j++)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

}

long double ele(double base, ll e) {
    long double ans = 1;
    while(e) {
        if(e&1) ans *= base;
        base *= base;
        e >>= 1;
    }
    return ans;
}

long double calc(int gol, int men, int ladies, int candy) {
    int tot = (men+ladies);
    long double chanceM = (men? (double)men/tot : 0);
    long double chanceL = (ladies? (double)ladies/tot : 0);
    return (ele(chanceM,gol)*ele(chanceL,(candy-gol))*dp[candy][(candy-gol)]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,w,c;
    cin >> n >> w >> c;
    pre();
    while(n or w) {
        long double ans = 0;
        for(int i = 0; i <= c; i+= 2)
            ans += calc(i,n,w,c);
        cout << fixed << setprecision(7) << ans << endl;
        cin >> n >> w >> c;
    }
    return 0;
}

