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
const int T = 1e3 + 10;
int n;
vii boxs;
int dp[T*T];

int solve(int i, int qtd, int res) {
    if(i == n) return 0;

    int &r = dp[res];
    if(r != -1) return r;

    int ans = 0;
    ans = solve(i+1, qtd, res);
    if(boxs[i].se < res and boxs[i].fi >= 0)
        ans = max(ans, solve(i+1, qtd+1, min(boxs[i].fi, res - boxs[i].se)) + 1);

    return r = ans;
}

bool cmp(const ii &a, const ii &b) {
    return a.fi > b.fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int a,b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        boxs.eb(b-a,a);
    }
    memset(dp, -1, sizeof dp);
    sort(boxs.begin(), boxs.end(), cmp);
    cout << solve(0,0,1e6) << endl;
    return 0;
}

