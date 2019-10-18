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

const int T = 1e6 + 5;
bool dp[2][T];
int a,b;

int main() {
    ios_base::sync_with_stdio(false);
    int n, v;
    cin >> a >> b >> n;

    memset(dp[0], 1, sizeof dp[0]);
    memset(dp[1], 0, sizeof dp[1]);

    for(int i = 1; i < T; i++) {
        if(i >= 1) dp[0][i] = min(dp[0][i],dp[1][i-1]), dp[1][i] = max(dp[1][i],dp[0][i-1]);
        if(i >= a) dp[0][i] = min(dp[0][i],dp[1][i-a]), dp[1][i] = max(dp[1][i],dp[0][i-a]);
        if(i >= b) dp[0][i] = min(dp[0][i],dp[1][i-b]), dp[1][i] = max(dp[1][i],dp[0][i-b]);
    }

    while(n--) {
        cin >> v;
        cout << (dp[0][v]? 'B' : 'A');
    }

    cout << endl;
    return 0;
}

