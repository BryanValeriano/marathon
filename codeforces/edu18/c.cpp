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

const int T = 1e5 + 10;
int dp[T][3][2];
bool pega[T][3][2];
string s;
int n;
bool flag;

int solve(int at, int mod, int has) {
    if(at == n) {
        if(has and !mod) return 0;
        else return -INF;
    }
    if(s[at] == '0') flag = true;

    int &d = dp[at][mod][has];
    if(d != -1) return d;

    int l = solve(at+1, mod, has);
    int r;
    if(!has and s[at] == '0') r = -INF;
    else r = solve(at+1, (mod + s[at] - '0') % 3, s[at] != '0'? 1 : has) + 1;

    pega[at][mod][has] = r >= l;
    return d = max(r,l);
}

void build(int at, int mod, int has) {
    if(at == n) { cout << endl; return; }
    if(pega[at][mod][has]) {
        cout << s[at];
        return build(at+1, (mod + s[at] - '0') % 3, s[at] != '0'? 1 : has);
    } 
    return build(at+1, mod, has);
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = s.size();
    ll ans = solve(0,0,0);
    if(ans < 0) {
        if(!flag) cout << -1 << endl;
        else cout << 0 << endl;
    } else {
        build(0,0,0);
    }
    return 0;
}

