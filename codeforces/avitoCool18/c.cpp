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
const int T = 2e3 + 10;
int n,m,k;
ll dp[T][T];


ll solve(int at, int disp, int dif, int used) {
    if(at == n and dif == k and disp >= 0) return 1;
    if(at == n) return 0;

    ll &r = dp[at][used];
    if(r != -1) return r;

    ll ans = 0;
    if(disp >= 1) ans += (at+1, disp-1, dif+1, used+1);
    if(disp >= 1) ans += (at+1, disp-1, dif+1, used + (used >= 2? 0 : 1));
    ans += (at+1, m-1, dif, used);

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    cout << solve(0, m, 0, 1) << endl;
    return 0;
}

