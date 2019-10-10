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

const int T = 1e3 + 4;
vector<int> rest;
int v[T];
int dp[T][T];
int choose[T][T];
int p[T];
string s;
int x,n;

bool solve(int at, int r) {
    if(at == n) return (r == 0);
    if(dp[at][r] != -1) return dp[at][r];

    if(s[at] != '?') {
        choose[at][r] = v[at];
        dp[at][r] = solve(at+1,(r+(v[at]*rest[at]))%x);
    } else {
        dp[at][r] = 0;
        for(int i = (at == 0); i < 10; i++) {
            bool ok = solve(at+1,(r+(i*rest[at]))%x);
            if(ok) { choose[at][r] = min(choose[at][r],i); dp[at][r] = 1; }
        }
    }

    return dp[at][r];
}

void build(int at,int r) {
    if(at == n) { cout << endl; return; }
    if(s[at] == '?') {
        cout << choose[at][r];
        build(at+1, (r+(choose[at][r]*rest[at]))%x);
    } else {
        cout << s[at];
        build(at+1, (r+(choose[at][r]*rest[at]))%x);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);
    memset(choose, INF, sizeof choose);

    cin >> s >> x;
    n = s.size();
    
    ll at = 1;
    for(int i = 0; i < n; i++) {
        rest.pb(at);
        at *= 10;
        at %= x;
        v[i] = s[i] - '0';
    }

    reverse(rest.begin(), rest.end());

    if(solve(0,0)) build(0,0);
    else cout << "*" << endl;
    
    return 0;
}

