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

const int T = 103;
const int N = 30;
const ll K = 1e12;

ll dp[T][T];
int last[T][N];
int n;
ll k;
string s;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;

    memset(last, -1, sizeof last);

    last[0][s[0]-'a'] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < N; j++) last[i][j] = last[i-1][j];
        last[i][s[i]-'a'] = i;
    }

    for(int i = 0; i < n; i++) dp[i][1] = 1;
    dp[last[n-1][s[0] - 'a']][0] = 1;
    
    for(int size = 2; size <= n; size++) {
        for(int ult = 1; ult < n; ult++) {

            for(int j = 0; j < N; j++) {
                if(last[ult-1][j] == -1) continue;
                    dp[ult][size] += dp[last[ult-1][j]][size-1];
                    dp[ult][size] = min(dp[ult][size], K);
            }
        }
    }

    ll ans = 0;

    for(int size = n; size >= 0; size--) {
        for(int j = 0; j < 30; j++) {
            if(last[n-1][j] == -1) continue;
            if(dp[last[n-1][j]][size] > 0) {
                if(k - dp[last[n-1][j]][size] >= 0) {
                    ans += dp[last[n-1][j]][size]* (n-size);
                    k -= dp[last[n-1][j]][size];
                } else {
                    ans += k * (n-size);
                    k = 0;
                }
            }
        }
    }
    
    //for(int j = 0; j < 30; j++) {
    //    for(int size = 0; size <= n; size++)
    //        cout << dp[last[n-1][j]][size] << " ";
    //    cout << endl;
    //}

    cout << (k? -1 : ans) << endl;

    return 0;
}

