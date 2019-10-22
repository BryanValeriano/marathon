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

const ll MOD = 1e9 + 7;
const int T = 2e5 + 4;
ll dp[10][T];
string s;
ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 1; i < 10; i++) dp[i][0] = i;

    for(ll j = 1; j < T; j++)
        for(int i = 1; i < 10; i++)
            dp[i][j] = (dp[i][j-1]*10ll) %MOD;

    for(ll j = 1; j < T; j++)
        for(int i = 1; i < 10; i++)
            dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;

    cin >> s;
    int n = s.size();
    for(ll i = 0; i < n; i++)
        ans = (ans + ((dp[s[i]-'0'][n-i-1]*(i+1)) % MOD)) %MOD;

    cout << ans << endl;

    return 0;
}

