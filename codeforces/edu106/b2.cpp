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
int dp[T][2][2];
int vis[T][2][2];
int vez;
string s;
int n;

int solve(int at, int last, bool ok) {
    if(at >= n) return 1;

    int &r = dp[at][last][ok];
    if(vis[at][last][ok]==vez) return r;

    if(ok) {
        if(s[at]-'0' < last) return 0;
        r = solve(at+1, s[at]-'0', !ok);
        vis[at][last][ok]  = vez;
        return r;
    }

    r = max(solve(at+1,last,!ok),
            (s[at]-'0' >= last? solve(at+1,s[at]-'0',ok) : 0));

    vis[at][last][ok]  = vez;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        n = s.size();
        ++vez;
        cout << (solve(0,0,0)?"yes":"no") << endl;
    }
    return 0;
}

