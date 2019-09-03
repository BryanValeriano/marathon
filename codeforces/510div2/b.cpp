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
int n;
vii v;
ll dp[1010][10];

ll solve(int i, int vit) {
    if(i == n and vit != 7) return INF;
    if(vit == 7) return 0;
    ll &r = dp[i][vit];
    if(r != -1) return r;

    ll ans = INF;
    ans = min(ans, solve(i + 1, vit | v[i].se) + v[i].fi);
    ans = min(ans, solve(i + 1, vit));

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int aux, aux2;
    string c;
    for(int i = 0; i < n; i++) {
        aux2 = 0;
        cin >> aux >> c;
        for(int j = 0; j < c.size(); j++) {
            if(c[j] == 'A') aux2 |= (1 << 0);
            else if(c[j] == 'B') aux2 |= (1 << 1);
            else if(c[j] == 'C') aux2 |= (1 << 2);
        }
        v.eb(aux,aux2);
    }
    memset(dp, -1, sizeof dp);
    ll ans = solve(0,0);
    cout << (ans == INF? -1: ans) << endl;
    return 0;
}

