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

const int T = 1e5 + 5;
ll v[T];
ll dp[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 2; i < n+2; i++) {
        int x; cin >> x;
        v[x+2]++;
    }

    ll ans = 0;

    for(ll i = 2; i < T; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + (i-2)*v[i]);
        ans = max(ans,dp[i]);
    }

    cout << ans << endl;

    return 0;
}

