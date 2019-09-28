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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e3 + 3;
const int N = 4100;

int n,m,gol;
ll v[T];
int key[T];
ll dp[T][N];

ll solve(int at, int mask) {
    if(mask == gol) return 0;
    if(at == m) return INF;
    if(dp[at][mask] != -1) return dp[at][mask];
    return dp[at][mask] = min(solve(at+1,mask), solve(at+1,mask|key[at])+v[at]);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    gol = pow(2,n)-1;

    for(int i = 0; i < m; i++) {
        cin >> v[i];
        int p; cin >> p;
        for(int j = 0; j < p; j++) {
            int x; cin >> x;
            key[i] |= (1 << (x-1));
        }
    }

    ll ans = solve(0,0);
    cout << (ans >= INF? -1 : ans) << endl;
    return 0;
}

