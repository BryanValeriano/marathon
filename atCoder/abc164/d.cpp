#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2020;
const int X = 2019;
const int N = 2e5 + 4;
int dp[2][T];
int rest[N];

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    rest[0] = 1;
    for(int i = 1; i < s.size(); i++) rest[i] = (rest[i-1]*10)%X;
    reverse(s.begin(),s.end());
    int at = 1;
    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        memset(dp[at], 0, sizeof dp[at]);
        int ok = ((s[i]-'0')*rest[i])%X;
        dp[at][ok]++;
        if(!ok) ans++;
        for(int j = T-1; j >= 0; j--) {
            if(!dp[!at][j]) continue;
            int x = (j+ok) % X;
            dp[at][x] += dp[!at][j];
            if(!x) ans += dp[!at][j];
        }
        at = !at;
    }

    cout << ans << endl;

    return 0;
}

