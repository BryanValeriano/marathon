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
const int T = 302;
const int N = 52;
int pre[T][T][N];
int dp[T][N];
int vis[T][N];
int id,n,d,vez;

int solve(int at, int din) {
    if(din >= d) return 0;
    if(at > n) return INF;
    if(vis[at][din] == vez) return dp[at][din];

    int ans = INF;
    for(int i = 0; i+din <= d; i++)
        ans = min(ans,solve(at+1,din+i)+pre[id][at][i]);

    vis[at][din] = vez;
    return dp[at][din] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        cin >> n >> d;
        vector<ll> v;
        memset(pre,INF,sizeof pre);
        int ans = INF;

        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            v.pb(x*50ll);
        }
        v.pb(1);
        sort(v.begin(),v.end());

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= d; k++) {
                    if(v[i]*k == v[j] and i) pre[i][j][k] = k-1;
                    else if(v[i]*k < v[j]) pre[i][j][k] = k;
                }
                pre[i][j][0] = 0;
            }
            pre[i][i][1] = 0;
        }


        for(int i = 0; i <= n; i++) {
            vez++;
            id = i;
            ans = min(ans,solve(0,0));
        }

        cout << "Case #" << ++cont << ": " << ans << endl;

    }
    return 0;
}

