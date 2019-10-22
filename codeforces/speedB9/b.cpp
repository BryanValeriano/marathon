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

ll dp[20][20];
int vis[20][20];
int vez;
string s;

ll solve(int at, int sum) {
    if(sum > 3) return 0;
    if(at == 20) return 1;
    if(vis[at][sum] == vez) return dp[at][sum];

    ll ans = 0;
    for(int i = s[at]-'0'; i <= 9; i++)
        ans += solve(at+1, sum + (i == 0));
    
    vis[at][sum] = vez;
    return dp[at][sum] = ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a,b; cin >> a >> b;

        vez++;
        s = to_string(a);
        while(s.size() < 20) s += '0';
        ll x = solve(0,0);

        vez++;
        s = to_string(b);
        while(s.size() < 20) s += '0';
        ll y = solve(0,0);
        
        cout << x-y << endl;
    }
    return 0;
}

