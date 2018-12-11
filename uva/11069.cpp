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
const int T = 80;
int dp[T];

int solve(int x) {
    if(x <= 0) return 0;
    int &m = dp[x];
    if(m != -1) return m;
    
    int l,r;
    l = r = 0;

    l = solve(x-3);
    r = solve(x-2);
    
    return m = l + r;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    solve(75);
    solve(76);
    int x;
    while(cin >> x) 
        cout << dp[x] << endl;
    
    return 0;
}

