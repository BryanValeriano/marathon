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
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

const int T = 2e5 + 3;
ll ponta[T][2];
ll best[T][2];
bool vis[T];

ll dp[T][4];
ll n,m,k,q;
ll last;
vector<ll> aprov;

ll travel(ll ori, ll mid, ll dest) {
    return abs(ori-mid) + abs(mid-dest);
}

ll solve(int at, int op) {
    if(dp[at][op] != -1) return dp[at][op];

    ll ans;
    int pos;
    pos = (op < 2? best[at][op] :  best[at-1][op-2]);
    if(at == 1) pos = 1;

    if(!vis[at]) return dp[at][op] = 1LL + min(solve(at+1,2) + abs(best[at][0] - pos), solve(at+1, 3) + abs(best[at][1] - pos));
    if(at == last) return dp[at][op] = min(travel(pos,ponta[at][0], ponta[at][1]), travel(pos, ponta[at][1], ponta[at][0]));

    ll esq1 = travel(pos, ponta[at][0], ponta[at][1]) + abs(best[at][1] - ponta[at][1]);
    ll esq2 = travel(pos, ponta[at][0], ponta[at][1]) + abs(best[at+1][1] - ponta[at][1]);
    ll dir1 = travel(pos, ponta[at][1], ponta[at][0]) + abs(best[at][0] - ponta[at][0]);
    ll dir2 = travel(pos, ponta[at][1], ponta[at][0]) + abs(best[at+1][0] - ponta[at][0]);

    ans = solve(at+1, 0) + dir2;
    ans = min(ans, solve(at+1, 1) + esq2);
    ans = min(ans, solve(at+1, 2) + dir1);
    ans = min(ans, solve(at+1, 3) + esq1);

    return dp[at][op] = 1LL + ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    ll a,b;
    cin >> n >> m >> k >> q;

    for(int i = 1; i <= n; i++) ponta[i][0] = INF;

    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        ponta[a][0] = min(ponta[a][0],b);
        ponta[a][1] = max(ponta[a][1],b);
        vis[a] = 1;
        last = max(a,last);
    }

    for(int i = last; i >= 1; i--)
        if(!vis[i]) ponta[i][0] = ponta[i+1][0], ponta[i][1] = ponta[i+1][1];

    for(int i = 0; i < q; i++) { cin >> a; aprov.pb(a); }

    sort(aprov.begin(), aprov.end());

    for(int i = 1; i <= last; i++) {
        ll pos = lower_bound(aprov.begin(), aprov.end(), ponta[i][0]) - aprov.begin();
        pos = min(pos, (ll)aprov.size()-1);
        best[i][0] = (abs(aprov[pos] - ponta[i][0]) <= abs(aprov[max(0ll,pos-1)] - ponta[i][0])? aprov[pos] : aprov[max(0ll,pos-1)]);

        pos = lower_bound(aprov.begin(), aprov.end(), ponta[i][1]) - aprov.begin();
        pos = min(pos, (ll)aprov.size()-1);
        best[i][1] = (abs(aprov[pos] - ponta[i][1]) <= abs(aprov[max(0ll,pos-1)] - ponta[i][1])? aprov[pos] : aprov[max(0ll,pos-1)]);
    }

    cout << solve(1,0) << endl;

    return 0;
}

