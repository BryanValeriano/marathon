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
const int T = 20;
const int N = (1<<T);
int adj[T][T];
ll dp[N][T];
int n;

int first(int mask) {
    for(int i = 0; i < n; i++)
        if((1<<i)&mask) return i;
    return 0;
}

bool ok(int mask, int i) {
    return (__builtin_popcount(mask) > 1 and
            ((1<<i)&mask) and i != first(mask));
}

int main() {
    ios_base::sync_with_stdio(false);
    int m; cin >> n >> m;

    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = 1;
    }

    int gol = (1<<n);
    for(int mask = 0; mask < gol; mask++)
        if(__builtin_popcount(mask)==1)
            dp[mask][(int)log2(mask)] = 1;

    for(int mask = 0; mask < gol; mask++)
        for(int i = 0; i < n; i++)
            if(ok(mask,i))
                for(int j = 0; j < n; j++)
                    if(adj[i][j])
                        dp[mask][i] += dp[mask^(1<<i)][j];

    ll ans = 0;
    for(int mask = 0; mask < gol; mask++)
        if(__builtin_popcount(mask) > 2)
            for(int i = 0; i < n; i++)
                if(adj[first(mask)][i])
                    ans += dp[mask][i];

    cout << (ans>>1) << endl;
    return 0;
}

