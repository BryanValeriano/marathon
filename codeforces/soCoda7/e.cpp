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

const int T = 40;
const int N = 2e5 + 5;

ll dp[T+3][N];

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b,h,w,n;
    cin >> a >> b >> h >> w >> n;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<ll>());

    ll lim = max(a,b);
    dp[0][min(lim,h)] = w;

    for(int i = 0; i < min(n,(ll)T); i++) {
        for(ll j = min(lim,h); j <= lim; j++) {
            if(dp[i][j]) {
                dp[i+1][min(lim,j*v[i])] = max(dp[i+1][min(lim,j*v[i])], dp[i][j]);
                dp[i+1][j] = max(dp[i+1][j], min(lim,dp[i][j]*v[i]));
            }
        }
    }

    for(int i = 0; i < min(n+1,(ll)T); i++) {
        for(ll j = min(a,b); j <= max(a,b); j++) {
            if(dp[i][j] >= a and j >= b) { cout << i << endl; return 0; }
            if(dp[i][j] >= b and j >= a) { cout << i << endl; return 0; }
        }
    }

    cout << -1 << endl;


    return 0;
}

