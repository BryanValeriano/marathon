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
const int N = 1e5 + 3;
ll dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n,c,w,v; cin >> n >> c;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> w >> v;
        for(int j = c; j-w >= 0; j--) {
            dp[j] = max(dp[j], dp[j-w] + v);
            ans = max(ans,dp[j]);
        }
    }

    cout << ans << endl;
    return 0;
}

