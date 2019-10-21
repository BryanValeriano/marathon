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

const int T = 202;
int dp[T];
int c,n;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> c >> n;
        memset(dp, 0, sizeof dp);

        int gol = (2 << (n+1)) - 1;
        int k,x;
        dp[0] = 1;
        int need = 0;
        int ok = 0;
        int ans = 0;

        while(n--) {
            cin >> k;
            need |= (1 << ok++);
            vector<int> save;
            while(k--) {
                cin >> x;
                for(int i = c; i-x >= 0; i--)
                    if(dp[i-x] == need) save.pb(i);
            }
            for(int i : save) {
                dp[i] = need | (1 << ok);
                if(!n) ans = max(ans,i);
            }
        }

        if(ans) cout << ans << endl;
        else cout << "no solution" << endl;
    }

    return 0;
}

