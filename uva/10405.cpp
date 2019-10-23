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

string s,t;
int dp[T][2];
 
int main() {
    ios_base::sync_with_stdio(false);
    while(getline(cin,s)) {
        getline(cin,t);
        s = 'a' + s;
        t = 'a' + t;
        memset(dp, 0, sizeof dp);
        int ans = 0;

        for(int i = 1; i < s.size(); i++) {
            int at = i%2, last = (i+1)%2;
            for(int j = 1; j < t.size(); j++) {
                if(s[i] == t[j]) dp[j][at] = 1 + dp[j-1][last];
                else dp[j][at] = max(dp[j][last], dp[j-1][at]);
                ans = max(ans,dp[j][at]);
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}

