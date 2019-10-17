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

const int T = 5e4 + 5;
const int N = 105;

int v[N];
int dp[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    while(m) {
        int n; cin >> n;
        for(int i = 0; i <= m; i++) dp[i] = INF;
        for(int i = 0; i < n; i++) cin >> v[i];

        dp[0] = 0;

        for(int i = 0; i < n; i++) 
            for(int j = m; j-v[i] >= 0; j--) 
                for(int k = 1; j-(v[i]*k) >= 0; k++)
                    dp[j] = min(dp[j],dp[j-(v[i]*k)]+k);
        
        if(dp[m] == INF) cout << "Impossivel" << endl;
        else cout << dp[m] << endl;
        cin >> m;
    }
    
    return 0;
}

