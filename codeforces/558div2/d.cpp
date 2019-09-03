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
string s,a,b;
int n;
int pi[T][2];
int dp[T][55][55];
bool vis[T][55][55];

void pre(string t, int op) {
    pi[0][op] = pi[1][op] = 0;

    for(int i = 2; i <= t.size(); i++) {
        pi[i][op] = pi[i-1][op];

        while(pi[i][op] > 0 and t[pi[i][op]] != t[i-1])
            pi[i][op] = pi[pi[i][op]][op];

        if(t[pi[i][op]] == t[i-1]) pi[i][op]++;
    }
}

int solve(int at, int x, int y) {
    //cout << at << " " << x << " " << y << endl;
    if(at == n) return 0;
    if(vis[at][x][y]) return dp[at][x][y];
    
    int ans = -INF;

    if(s[at] == '*') {
        for(char i = 'a'; i <= 'z'; i++) {
            int xx = x;
            int yy = y;
            while(xx > 0 and i != a[xx]) xx = pi[xx][0];
            while(yy > 0 and i != b[yy]) yy = pi[yy][1];
            xx += (a[xx] == i);
            yy += (b[yy] == i);
            ans = max(ans, solve(at+1, xx , yy) + (xx == (a.size()-1)) - (yy == (b.size()-1)));
        }
    } else {
        int xx = x;
        int yy = y;
        while(xx > 0 and s[at] != a[xx]) xx = pi[xx][0];
        while(yy > 0 and s[at] != b[yy]) yy = pi[yy][1];
        xx += (a[xx] == s[at]);
        yy += (b[yy] == s[at]);
        ans = max(ans, solve(at+1, xx , yy) + (xx == (a.size()-1)) - (yy == (b.size()-1)));
    }
    
    vis[at][x][y] = 1;
    return dp[at][x][y] = ans; 

}

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> a >> b;
    n = s.size();
    s += '#';
    a += '$';
    b += '$';
    pre(a,0);
    pre(b,1);

    cout << solve(0, 0, 0) << endl;

    return 0;
}

