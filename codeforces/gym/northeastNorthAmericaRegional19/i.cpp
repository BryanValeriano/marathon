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

    int last = 0;
    dp[last][0][0] = 0;
    ll ans = INF;

    while(n--) {
        int at = !last;
        memset(dp[at], INF, sizeof dp[at]);

        string x; cin >> x;
        ll cost; cin >> cost;

        for(int i = 1; i < s.size(); i++) {
            int cobre = fim(i,x);
            if(cobre == -1) continue;
            cout << x << " " << cobre << endl;
            //quero preencher toda a dp[i][i..fim]
            for(int j = i; j <= cobre; j++) {
                //dp[i][j] deve ser o menor custo
                //dp[at][i][j] = min(dp[at][i][j],dp[last][0..(i-1)][(j-1)])
                for(int k = 0; k < i; k++) {
                    for(int p = i-1; p <= j-1; p++) {
                        dp[at][i][j] = min(dp[at][i][j], dp[last][k][p]+cost);
                        if(dp[at][i][j] != INF) {
                            cout << x << endl;
                            cout << i << " " << j << " = " << dp[at][i][j] << endl;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                dp[last][i][j] = min(dp[at][i][j],dp[last][i][j]);
                if(j == (s.size()-1)) ans = min(ans, dp[last][i][j]);
            }

        last = !last;
    }

    if(ans == INF) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;

    return 0;
}

