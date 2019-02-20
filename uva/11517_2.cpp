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
const int T = 102;
const int N = 4e4;
int v[T];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int n,gol;
    while(tc--) {
        cin >> gol >> n;
        memset(dp, INF, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++)
            for(int j = 30001; j >= 0; j--) 
                if(dp[j] < INF) dp[j + v[i]] = min(dp[j + v[i]], dp[j] + 1);
        for(int i = gol; i < N; i++)
            if(dp[i] != INF) { cout << i << " " << dp[i] << endl; break; }

    }
    return 0;
}

