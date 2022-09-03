#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const int T = 8e3+1;
// 0 min
// 1 max
ll dp[2][T][T];
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp[0], sizeof dp[0], INF);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int s = 0; s < 2; s++) {
    for(int i = 1; i < n; i++) cin >> v[i];
        for(int k = 1; k < n; k++) {
            for(int i = 1; i < n; i++) {
                if(s) dp[s][k][i] = max(dp[s][k][i], dp[s][k-1][i-1]);

            }
        }
    }

    return 0;
}

