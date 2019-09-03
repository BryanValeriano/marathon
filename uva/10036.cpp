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

const int T = 1e4 + 2;
const int N = 101;

int n,k;
int v[T];
bool dp[T][N];
int flag;

bool solve(int at, int mod) {
    cout << at << " " << mod << endl;
    if(at == n) {
        if(mod == 0) flag = 1;
        return flag;
    }
    if(flag) return flag;
    if(dp[at][mod] != -1) return dp[at][mod];
    return dp[at][mod] = max(solve(at+1, (mod + v[at]) % k), solve(at+1, (((mod - v[at]) % k)+k)%k));
}

bool solve2(int ini) {
    dp[1][ini] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 0; j < N; j++) 
            if(dp[i][j]) {
                int s = (j + v[i]) % k;
                dp[i+1][s] = 1;
                s = (j - v[i]) % k;
                s = (s+k) % k;
                dp[i+1][s] = 1;
            }

    return (dp[n][0] == 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    string ans;
    string x = "Divisible\n";
    string y = "Not divisible\n";

    while(tc--) {
        cin >> n >> k;
        int ini; cin >> ini;
        ini = abs(ini)%k;
        for(int i = 1; i < n; i++) cin >> v[i], v[i] = abs(v[i]) % k;
        //memset(dp, -1, sizeof dp);
        memset(dp, 0, sizeof dp);
        //flag = 0;
        if(solve2(ini)) ans += x;
        else ans += y;
    }

    cout << ans;

    return 0;
}

