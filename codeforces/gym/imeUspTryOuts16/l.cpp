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
const int T = 1e6+5;
ll dp[T];

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -INF, sizeof dp);
    int n,s; cin >> n >> s;
    s = min(T-1,s);
    dp[0] = 0;
    while(n--) {
        int w;
        ll c;
        cin >> w >> c;
        for(int j = 0; j+w <= s; j++) dp[j+w] = max(dp[j+w], dp[j]+c);
    }
    ll ans = 0;
    for(int i = 0; i <= s; i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}

