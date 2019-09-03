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

const int T = 1005;

int n,m,x,y;
int v[T];
int dp[T][T][3];

int solve(int at, int seq, int last) {
    if(seq > y) return INF;
    if(at == m) return (seq >= x? 0 : INF);
    if(dp[at][seq][last] != -1) return dp[at][seq][last];
   
    int ans = INF;
    if(!(last == 0 and seq < x)) ans = solve(at+1, (last == 1? seq + 1 : 1), 1) + n - v[at]; 
    if(!(last == 1 and seq < x)) ans = min(ans, solve(at+1, (last == 0? seq + 1 : 1), 0) + v[at]);
    
    return dp[at][seq][last] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> x >> y;
    char z;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            { cin >> z; if(z == '#') v[j]++; }
    
    cout << solve(0,x,2) << endl;

    return 0;
}

