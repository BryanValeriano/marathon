#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 2e4 + 3;
int dp[5][T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int x;
    int alt = 0;
    int last = 0;
    int aux[4];
    aux[0] = aux[2] = 1;
    aux[1] = aux[3] = 2;
    for(int i = 0; i < n; i++) {
        cin >> x; 
        if(x != last) alt = min(3, alt + 1);
        for(int j = 0; j <= 3; j++) {
            if(j != 0 && i != 0) dp[j][i] = max(dp[j][i], max(dp[j - 1][i], dp[j][i - 1]));
            else if(j == 0 && i != 0) dp[j][i] = max(dp[j][i - 1], dp[j][i]);
            else if(i == 0 && j != 0) dp[j][i] = max(dp[j - 1][i], dp[j][i]);
        }
        for(int j = 0; j <= alt; j++)
            if(x == aux[j])
                dp[j][i]++;
        for(int j = 0; j <= 3; j++) {
            if(j != 0 && i != 0) dp[j][i] = max(dp[j][i], max(dp[j - 1][i], dp[j][i - 1]));
            else if(j == 0 && i != 0) dp[j][i] = max(dp[j][i - 1], dp[j][i]);
            else if(i == 0 && j != 0) dp[j][i] = max(dp[j - 1][i], dp[j][i]);
        }
        last = x;
    }

    //for(int j = 0; j < n; j++)
    //    cout << j << " ";
    //cout << endl;
    //for(int i = 0; i < 4; i++) {
    //    for(int j = 0; j < n; j++)
    //        cout << dp[i][j] << " ";
    //    cout << endl;
    //}
    cout << dp[3][n-1] << endl;
    return 0;
}

