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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 402;
int dp[T][T];
int vis[T][T];
int n, vez;
vector<int> v;

int solve(int t, int p) {
    if(p == n) return 0;
    if(t >= 401) return INF;
    int &r = dp[t][p];
    if(vis[t][p] == vez) return r;
    vis[t][p] = vez;
    return r = min(solve(t+1,p),solve(t+1,p+1)+abs(t-v[p]));
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        v.clear();
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v.pb(x);
        }
        sort(v.begin(),v.end());
        vez++;
        cout << solve(1,0) << endl;
    }
    return 0;
}

