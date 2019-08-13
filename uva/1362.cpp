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

const int T = 302;
const int MOD = 1e9;
ll dp[T][T];
int vis[T][T];
int t;
string s;

ll solve(int l, int r) {
    if(l == r) return 1;
    if(s[l] != s[r]) return 0;
    if(vis[l][r] == t) return dp[l][r];

    ll ans = 0;

    for(int i = 1; l+i <= r; i++) 
        if(s[l] == s[l+i]) ans = (ans + solve(l+1,l+i-1) * solve(l+i,r)) % MOD;

    vis[l][r] = t;
    return dp[l][r] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> s) {
        t++;
        cout << solve(0,s.size()-1) << endl;
    }
    return 0;
}

