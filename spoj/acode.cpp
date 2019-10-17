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

const int T = 5e3 + 5;
ll dp[T];
int vis[T];
string s;
int n, vez;

ll solve(int at) {
    if(at == n) return 1;
    if(s[at] == '0') return 0;
    if(vis[at] == vez) return dp[at];

    ll ans = 0;
    ans += solve(at+1);

    if(at+1 < n) { 
        int x = (s[at]-'0')*10 + (s[at+1]-'0');
        if(x >= 1 and x <= 26) ans += solve(at+2);
    }

    vis[at] = vez;
    return dp[at] = ans;
}

 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    while(s != "0") {
        vez++;
        n = s.size();
        cout << solve(0) << endl;
        cin >> s;
    }

    
    
    return 0;
}

