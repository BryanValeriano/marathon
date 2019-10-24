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

const int T = 55;

int dp[55][2555];
int vis[55][2555];
int n;
int a,b,vez;
int v[T];
int acum[T];

int ok(int x, int y) {
    if((x&1) and (y&1)) return 0;
    return 1;
}

int solve(int at, int um) {
    if(at > n) return 0;
    if(vis[at][um] == vez) return dp[at][um];
    int ans = 0;
    
    int dois = acum[at-1]-um;

    for(int i = 0; i <= v[at]; i++)
        if(um + i <= a and dois + (v[at]-i) <= b)
            ans = max(ans, solve(at+1,um+i)+ok(i,v[at]-i));
   
    vis[at][um] = vez;
    return dp[at][um] = ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    string s;

    while(tc--) {
        cin >> n;
        a = b = 0;
        
        memset(acum, 0, sizeof acum);

        for(int i = 1; i <= n; i++) {
            cin >> s;
            v[i] = s.size();
            acum[i] = v[i];
            acum[i] += acum[i-1];
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == '1') a++;
                else b++;
            }
        }
        
        vez++;
        cout << solve(1,0) << endl;
    } 

    return 0;
}

