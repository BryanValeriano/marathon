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

const int T = 255;
ll dp[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m;
    dp[0] = 1;
    while(m--) {
        cin >> x;
        for(int i = n; i-x >= 0; i--) {
            int y = x;
            while(i-y >= 0) dp[i] += dp[i-y], y += x;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

