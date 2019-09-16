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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 5;
ll maxi[T];
int prox[T];
int w[T];
int n,m,k;
int d[T];
vector<int> fim[T];
vector<int> ini[T];
multiset<ii> bag;

ll dp[T][202];

ll solve(int at, int q) {
    if(at > n) return 0;
    if(dp[at][q] != -1) return dp[at][q];

    ll ans = INF;
    if(q < m) ans = min(ans, solve(at+1, q+1));
    ans = min(ans, solve(prox[at], q) + maxi[at]);

    return dp[at][q] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    int s,t;

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> s >> t >> d[i] >> w[i];
        ini[s].pb(i);
        fim[t+1].pb(i);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < ini[i].size(); j++) {
            int x = ini[i][j];
            bag.insert(mk(w[x], d[x]));
        }
        for(int j = 0; j < fim[i].size(); j++) {
            int x = fim[i][j];
            bag.erase(bag.find(mk(w[x], d[x])));
        }
        if(bag.size()) {
            ii at = *bag.rbegin();
            maxi[i] = at.fi;
            prox[i] = at.se+1;
        } else prox[i] = i+1;
    }

    cout << solve(1,0) << endl;

    return 0;
}

