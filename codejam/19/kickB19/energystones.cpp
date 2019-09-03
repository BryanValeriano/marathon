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

const int N = 110;
const int T = 1e4 + 10;

struct node {
    ll s,e,l;
};

int n; 
vector<node> v;
ll dp[N][T];

ll solve(int at, ll t) {
    if(at == n) return 0;
    if(dp[at][t] != -1) return dp[at][t];

    ll ans = solve(at+1, t);
    ans = max(ans, solve(at+1, t+ v[at].s) + (v[at].e - (v[at].l * t)));

    return dp[at][t] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    int cont = 0;
    int tc; cin >> tc;
    ll s,e,l;
    while(tc--) {
        memset(dp, -1, sizeof dp);
        v.clear();
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> s >> e >> l;
            v.pb({s,e,l});
        }

        sort(v.begin(), v.end(), [] (const node &a, const node &b) { return (a.l * b.s) >  (b.l * a.s); });
        cout << "Case #" << ++cont << ": " << solve(0,0) << endl;
    }

    return 0;
}

