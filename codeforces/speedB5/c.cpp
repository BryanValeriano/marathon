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

const int T = 1e5 + 2;
int dp[T][3][3];
int n;
string s;

int solve(int at, int peg, int last) {
    if(at == n) return 0;
    int &r = dp[at][peg][last];
    if(r != -1) return r;

    int ans = solve(at+1,peg,last);
    if(peg < 2) ans = max(ans, solve(at+1,peg+1,last));

    if(peg == 0 or peg == 2) {
        bool ok = s[at]-'0';
        if(ok != last) {
            ans = max(ans, solve(at+1, peg, ok)+1);
            if(peg == 0) ans = max(ans, solve(at+1, peg+1, ok)+1);
        }
    }

    else if(peg == 1) {
        bool ok = s[at]-'0';
        ok = (!ok);
        if(ok != last) 
            ans = max({ans, solve(at+1, peg, ok)+1, solve(at+1, peg+1, ok)+1});
    }

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> s;
    cout << max(solve(0,0,2), solve(0,1,2)) << endl;
    return 0;
}

