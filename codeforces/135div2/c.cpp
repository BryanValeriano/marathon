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

int n,k;
string s;
const int T = 5e5 + 5;

int dp[T][30];
int re[T][30];

int solve(int at, int c) {
    if(at == n) return 0;
    if(dp[at][c] != -1) return dp[at][c];

    bool custo = 0;
    if(c + 'A' != s[at]) custo++;
    int ans = INF;
   
    if(c + 'A' != s[at+1]) {
        ans = solve(at+1, s[at+1] - 'A') + custo;
        re[at][c] = s[at+1] - 'A';
    }
    
    for(int i = 0; i < k; i++) {
        if(i == c) continue;
        int l = solve(at+1,i) + custo;
        if(l < ans) {
            ans = l;
            re[at][c] = i;
        }
        if(i + 'A' != s[at+2]) return dp[at][c] = ans;
    }

    return dp[at][c] = ans;
}

void build(int at, int c) {
    if(at == n) return;
    cout << (char)(c + 'A');
    build(at+1, re[at][c]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(dp, -1, sizeof dp);
    cin >> n >> k >> s;

    s += '#';
   
    int ans = INF;
    int ini;

    for(int i = 0; i < k; i++) {
        int l = solve(0,i);
        if(l < ans) {
            ans = l;
            ini = i;
        }
    }

    cout << ans << endl;
    build(0, ini);
    cout << endl;

    return 0;
}

