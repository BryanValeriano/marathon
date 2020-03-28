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

const int T = 1e6 + 3;
const int N = 2;
int v[T];
string s;
ll dp[T][N];

ll solve(int at, bool carry) {
    if(at == s.size()) return carry;
    if(~dp[at][carry]) return dp[at][carry];
    ll x = v[at]+carry;
    ll y = (10-x);
    dp[at][carry] = 1e18;
    if(x < 10) dp[at][carry] = min(dp[at][carry],solve(at+1,0)+x);
    return dp[at][carry] = min(dp[at][carry], solve(at+1,1)+y);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> s;
    reverse(s.begin(),s.end());
    for(int i = 0; i < s.size(); i++) v[i] = (s[i]-'0');
    cout << solve(0,0) << endl;
    return 0;
}

