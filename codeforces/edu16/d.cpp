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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 2e7 + 10;

ll dp[T];
ll n,x,y;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;

    for(ll i = 1; i < T; i++) dp[i] = i*x; 

    for(ll i = 1; i < T; i++) {  
        if(i+i < T) dp[i+i] = min(dp[i+i], dp[i] + y);
        if(i+1 < T) dp[i+1] = min(dp[i+1], dp[i] + x);
        dp[i-1] = min(dp[i-1], dp[i] + x);
        if(!(i&1)) dp[i/2] = min(dp[i/2], dp[i] + (i/2) * x);
        if(i > n) dp[n] = min(dp[n], dp[i] + (i-n)*x);
    }

    cout << dp[n] << endl;
    return 0;
}

