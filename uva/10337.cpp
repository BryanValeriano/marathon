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

int mat[1000][10];
int dp[1000][10];
int x;

int solve(int at, int alt) {
    if(alt < 0 or alt > 9) return INF; 
    if(at == x) return (alt == 0? 0 : INF);

    int &r = dp[at][alt];
    if(r != -1) return r;

    int ans = INF;
    ans = min(ans, solve(at+1, alt+1) + 60 - mat[at][alt]);
    ans = min(ans, solve(at+1, alt) + 30 - mat[at][alt]);
    ans = min(ans, solve(at+1, alt-1) + 20 - mat[at][alt]);

    return r = ans;
}



int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        memset(dp, -1, sizeof dp);
        cin >> x;
        x /= 100;
        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < x; j++)
                cin >> mat[j][i];
    
        cout << solve(0,0) << endl;
        cout << endl;
    }

    return 0;
}

