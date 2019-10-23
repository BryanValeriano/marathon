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

const int T = 1e3;

string s,t;
int dp[T][2];
 
int main() {
    ios_base::sync_with_stdio(false);
    while(cin >> s) {
        cin >> t;
        s = 'a' + s;
        t = 'a' + t;
        memset(dp, 0, sizeof dp);

        for(int i = 1; i < s.size(); i++) {
            int at = i%2, last = (i+1)%2;
            for(int j = 1; j < t.size(); j++) {
                if(s[i] == t[j]) dp[j][at] = 1 + dp[j][last];
                else dp[j][at] = max(dp[j][last], dp[j-1][at]);
            }
        }

        int m = t.size()-1;
        int x = (s.size()-1)%2;
        cout << dp[m][x] << endl;
    }
    
    return 0;
}

