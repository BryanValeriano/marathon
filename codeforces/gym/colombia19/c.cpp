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
int dp[2*T + 5][2];
 
int main() {
    ios_base::sync_with_stdio(false);
    string s,t; cin >> s >> t;
    
    int ans = 0;
    int n = s.size();

    for(int i = 0; i < n; i++) { 
        int at = i%2, last = (i+1)%2;
        int m = min(n-1,T);
        int d = max(-T+1, -i); 

        for(; d < m; d++) {
            int j = i+d;
            if(s[i] == t[j]) dp[T+d][at] = 1 + dp[T + d][last];
            else dp[T + d][at] = max(dp[T+d-1][at], dp[T+d+1][last]);
            ans = max(ans,dp[T+d][at]);
        }
    }
    
    int ok = (99*n)/100;
    if((99*n)%100) ok++;

    cout << (ans >= ok? "Long lost brothers D:" : "Not brothers :(") << endl; 
    return 0;
}

