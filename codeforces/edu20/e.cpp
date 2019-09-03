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

const int T = 1e3 + 5;

int n,k;
string s;

int dp[T][T];
int choose[T][T];

bool solve(int at, int saldo) {
    if(at == n) return (abs(saldo) == k? 1 : 0);
    if(abs(saldo) == k) return false;
    if(dp[at][saldo] != -1) return dp[at][saldo];

    if(s[at] != '?') {
        int x = 0;
        if(s[at] == 'L') x--;
        else if(s[at] == 'W') x++;
        return dp[at][saldo] = solve(at+1, saldo + x);
    }

    bool l = solve(at+1, saldo+1);
    bool r = solve(at+1, saldo-1);
    bool m = solve(at+1, saldo);

    if(l == 1) choose[at][saldo] = 1;
    else if(r == 1) choose[at][saldo] = -1;
    else if(m == 1) choose[at][saldo] = 0;
    else choose[at][saldo] = 2;

    return dp[at][saldo] = max({m,l,r});
}

void build(int at, int saldo) {
    if(at == n) { cout << endl; return; }
    if(s[at] != '?') { 
        int x = 0;
        if(s[at] == 'L') x--;
        else if(s[at] == 'W') x++;
        cout << s[at];
        build(at+1, saldo + x);
    } else {
        if(choose[at][saldo] == 0) cout << 'D';
        else if(choose[at][saldo] == 1) cout << 'W';
        else cout << 'L';
        build(at+1, saldo + choose[at][saldo]);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> s;
    if(solve(0,0) == 1) {
        build(0,0);
    } else cout << "NO" << endl;
    return 0;
}

