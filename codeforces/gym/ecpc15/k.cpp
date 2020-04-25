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
const int T = 1e6+1;
const int N = 200;
int dp[T][N];
int vis[T][N];

ll a,b,n,p,vez;
vector<int> s;
vector<int> r;

int solve(int pos, int rest) {
    if(pos > n) return (!rest);
    int &d = dp[pos][rest];
    if(vis[pos][rest] == vez) return d;
    vis[pos][rest] = vez;
    d = solve(pos+1,(r[pos]*s[pos]+rest)%p)+(!rest);
    return d;
}



int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> a >> b >> n >> p;
        double ok = (double)a/(double)b;

        s.clear();

        for(int i = 0; i < n; i++) {
            if((ll)ok <= 0) ok *= 10;
            s.pb(((ll)ok)%10);
            ok -= (ll)s.back();
        }
        s.pb(0);

        reverse(s.begin(),s.end());
        r.clear();
        r.pb(0);

        for(int i = 1; i <= n; i++) {
            r.pb(r[i-1]);
            r[i] *= 10ll;
            r[i] %= p;
        }

        vez++;
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += (ll)solve(i+1,(r[i]*s[i])%p);
        }

        cout << ans << endl;
    }
    return 0;
}

