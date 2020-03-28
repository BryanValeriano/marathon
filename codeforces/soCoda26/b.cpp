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
const int T = 500*500+1;
bool dp[T];

int main() {
    ios_base::sync_with_stdio(false);
    dp[0] = 1;
    int n,k; cin >> n >> k;
    while(n--) {
        int x; cin >> x;
        for(int i = T-x; i-x >= 0; i--) dp[i] |= dp[i-x];
    }
    vector<int> ans;
    for(int i = 0; i+k < T; i++) if(dp[i] and dp[i+k]) ans.pb(i);

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

