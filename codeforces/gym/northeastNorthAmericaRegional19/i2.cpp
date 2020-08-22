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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const int T = 502;
const int N = 1e3+2;
string s;
int n;
ll dp[2][N][N];

int fim(int ini, string x) {
    int ans = -1;

    for(int i = ini; i < s.size() and i-ini < x.size(); i++) {
        if(s[i] == x[i-ini]) ans = i;
        else break;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,INF,sizeof dp);
    cin >> s >> n;
    s = "#" + s;

    dp[1][0][0] = 0;
    ll ans = INF;

    while(n--) {
        string x; cin >> x;
        ll cost; cin >> cost;
        for(int i = 1; i < s.size(); i++) {
            if(i + x.size() > s.size()) break;
            int match = fim(i,x);
            if(match == -1) continue;
            for(int j = i; j < i+x.size(); j++) {
                dp[j][(j<=match)][i+(x.size()-1)] = min(dp[j][(j<=match)][i+(x.size()-1)],dp[j][

            }
        }
    }

    if(ans == INF) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;

    return 0;
}

